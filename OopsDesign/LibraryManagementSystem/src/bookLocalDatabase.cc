#include "bookLocalDatabase.h"

#include <cassert>
#include <cstdint>
#include <tuple>
#include <utility>

std::uint32_t LocalBookStore::s_bookId = 0;

void LocalBookStore::addItem(const Book& book) {
    auto it = m_booksByName.find(book.getTitle());
    if (it != m_booksByName.end()) {
        // check if we have a reference already
        for (auto id : it->second) {
            if (auto entryIt = m_books.find(id); entryIt != m_books.end()) {
                auto& entry = entryIt->second;
                if (entry.m_book.getPublishDate() == book.getPublishDate()) {
                    entry.addCopy();
                    if (entry.getAvailableCopies() == 1) {
                        notify(entry.m_book, "Available");
                    }
                    return;
                }
            } else {
                assert(false);
            }
        }
    }

    m_booksByName[book.getTitle()].emplace_back(++s_bookId);
    auto ret = m_books.emplace(
        std::piecewise_construct, std::forward_as_tuple(s_bookId),
        std::forward_as_tuple(book.getTitle(), book.getIsbn(),
                              book.getAuthor().m_name, book.getPublishDate(),
                              s_bookId));
    ret.first->second.addCopy();
    if (ret.first->second.getAvailableCopies() == 1) {
        notify(ret.first->second.m_book, "Available");
    }
}

// Only Queryable item
void LocalBookStore::removeItem(const Book& book) {
    auto bookId = book.getBookId();
    if (auto it = m_books.find(bookId); it != m_books.end()) {
        if (it->second.removeCopy() == 0) {
            m_books.erase(it);
        }
        if (auto it2 = m_booksByName.find(book.getTitle());
            it2 != m_booksByName.end()) {
            auto& ids = it2->second;
            ids.erase(std::remove(ids.begin(), ids.end(), bookId));
            if (ids.empty()) {
                m_booksByName.erase(it2);
            }
        }
    }
}

void LocalBookStore::updateItem(const Book& book) {}

Books LocalBookStore::getItemByProperty(const BookProperty& property) {
    Books books;
    for (const auto& entry : m_books) {
        if (property.isSatisfied(entry.second.m_book)) {
            books.emplace_back(entry.second.m_book);
            books.back().setAvailableCopies(entry.second.getAvailableCopies());
        }
    }
    return books;
}

Books LocalBookStore::getItemById(const BookId bookId) {
    Books books;
    if (auto it = m_books.find(bookId); it != m_books.end()) {
        books.emplace_back(it->second.m_book);
    }
    return books;
}
