#include "library.h"

#include "bookLocalDatabase.h"

Books BookSearch::searchByTitle(std::string title) {
    BookPropertyTitle property(title);
    return BookDb::getInstance().getItemByProperty(property);
}

Books BookSearch::searchByAuthor(std::string author) {
    BookPropertyAuthor property(Author{author});
    return BookDb::getInstance().getItemByProperty(property);
}

Books BookSearch::searchByPublicationDate(std::string publicationDate) {
    BookPropertyPublication property(publicationDate);
    return BookDb::getInstance().getItemByProperty(property);
}

void ManageLibrary::addBook(std::string title, std::string isbn,
                            std::string author, std::string publishDate) {
    Book book(title, isbn, author, publishDate);
    BookDb::getInstance().addItem(book);
}

void ManageLibrary::deleteBook(BookId id) {
    auto& db   = BookDb::getInstance();
    auto  book = db.getItemById(id);
    db.removeItem(book[0]);
}

void ManageLibrary::registerMember(uint32_t memberId) {}

void BookTransaction::checkIn(const Book& book) {}

void BookTransaction::checkout(const Book& book) {}
