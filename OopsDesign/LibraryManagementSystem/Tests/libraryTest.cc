#include "bookDatabaseInterface.h"
#include "bookLocalDatabase.h"
#include "gtest/gtest.h"
#include "libraryUser.h"

TEST(Library, Librarian) {
    Librarian librarian("Gobind", "Bangalore");
    librarian.addBook("First Book", "123456", "Gobind Prasad", "12/1/2022");
    librarian.addBook("First Book", "123456", "Gobind Prasad", "12/1/2022");
    librarian.addBook("First Book", "123456", "Gobind Prasad", "12/1/2022");
    librarian.addBook("First Book", "123456", "Gobind Prasad", "12/1/2022");

    BookPropertyAuthor property(Author{"Gobind Prasad"});
    auto books = BookDb::getInstance().getItemByProperty(property);
    EXPECT_EQ(books.size(), 1);
    EXPECT_EQ(books[0].getAvailableCopies(), 4);

    librarian.addBook("Second Book", "123456", "Gobind Prasad", "12/1/2022");
    librarian.addBook("Second Book", "123456", "Gobind Prasad", "12/1/2022");
    librarian.addBook("Second Book", "123456", "Gobind Prasad", "12/1/2022");

    books = BookDb::getInstance().getItemByProperty(property);
    EXPECT_EQ(books.size(), 2);
    EXPECT_EQ(books[0].getAvailableCopies(), 3);
}
