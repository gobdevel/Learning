#pragma once
#include "bookDatabaseInterface.h"

class BookEntry;
using BookEntries = std::vector<BookEntry>;

class BookEntry {
    friend class LocalBookStore;

public:
    template <typename... Args>
    BookEntry(Args... args) : m_book(std::forward<Args>(args)...) {}
    void addCopy() {
        m_numCopies += 1;
        m_availableCopies += 1;
    }
    int removeCopy() {
        if (m_numCopies > 0) {
            m_numCopies -= 1;
            m_availableCopies -= 1;
        }
        return m_numCopies;
    }
    bool isAvailable() { return m_availableCopies > 0; }
    int  getAvailableCopies() const { return m_availableCopies; }

private:
    int  m_numCopies{0};
    int  m_availableCopies{0};
    Book m_book;
};

class LocalBookStore : public BookDataBaseInterface {
public:
    void  addItem(const Book& book) override;
    void  removeItem(const Book& book) override;
    void  updateItem(const Book& book) override;
    Books getItemByProperty(const BookProperty& property) override;
    Books getItemById(const BookId bookId) override;

private:
    using BookIds              = std::vector<BookId>;
    using BookEntryStore       = std::unordered_map<BookId, BookEntry>;
    using BookEntryByNameStore = std::unordered_map<std::string, BookIds>;

    BookEntryStore       m_books;
    BookEntryByNameStore m_booksByName;
    static std::uint32_t s_bookId;
};

class BookDb {
public:
    static BookDataBaseInterface& getInstance() {
        static LocalBookStore s_bookStore;
        return s_bookStore;
    }
};
