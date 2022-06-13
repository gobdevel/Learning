#pragma once

#include "bookDatabaseInterface.h"

class BookSearch {
public:
    Books searchByTitle(std::string titile);
    Books searchByAuthor(std::string author);
    Books searchByPublicationDate(std::string publicationDate);
};

class ManageLibrary {
public:
    void addBook(std::string title, std::string isbn, std::string author,
                 std::string publishDate);
    void deleteBook(BookId id);
    void registerMember(uint32_t memberId);
};

class BookTransaction {
public:
    void checkIn(const Book& book);
    void checkout(const Book& book);
};
