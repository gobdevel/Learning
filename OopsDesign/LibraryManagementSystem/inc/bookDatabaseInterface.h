#pragma once
#include <string>
#include <unordered_map>
#include <vector>

#include "dbInterface.h"

class Book;
using Books                 = std::vector<Book>;
using BookProperty          = Property<Book>;
using BookDataBaseInterface = DbInterface<Book>;
using BookId                = std::uint32_t;

struct Author {
    std::string m_name;
};

inline bool operator==(const Author& lhs, const Author& rhs) {
    return !lhs.m_name.compare(rhs.m_name);
}

class Book {
public:
    Book(std::string title, std::string isbn, std::string author,
         std::string publishDate)
        : m_title(std::move(title)),
          m_isbn(std::move(isbn)),
          m_author{std::move(author)},
          m_publishDate{std::move(publishDate)} {}

    Book(std::string title, std::string isbn, std::string author,
         std::string publishDate, BookId id)
        : Book(title, isbn, author, publishDate) {
        m_bookId = id;
    }
    const std::string& getTitle() const { return m_title; }
    const std::string& getIsbn() const { return m_isbn; }
    const std::string& getPublishDate() const { return m_publishDate; }
    const Author&      getAuthor() const { return m_author; }
    BookId             getBookId() const { return m_bookId; }
    int                getAvailableCopies() const { return m_availableCopies; }
    void setAvailableCopies(int nums) { m_availableCopies = nums; }

private:
    std::string m_title;
    std::string m_isbn;
    std::string m_publishDate;
    Author      m_author;
    int         m_availableCopies{0};
    BookId      m_bookId{0};
};

class BookPropertyTitle : public BookProperty {
public:
    explicit BookPropertyTitle(std::string title) : m_title(std::move(title)) {}
    bool isSatisfied(const Book& book) const override {
        return !m_title.compare(book.getTitle());
    }

private:
    std::string m_title;
};

class BookPropertyPublication : public BookProperty {
public:
    explicit BookPropertyPublication(std::string pub) : m_pub(std::move(pub)) {}
    bool isSatisfied(const Book& book) const override {
        return !m_pub.compare(book.getPublishDate());
    }

private:
    std::string m_pub;
};

class BookPropertyAuthor : public BookProperty {
public:
    explicit BookPropertyAuthor(Author author) : m_author(std::move(author)) {}
    bool isSatisfied(const Book& book) const override {
        return m_author == book.getAuthor();
    }

private:
    Author m_author;
};
