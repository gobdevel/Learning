#include "bookDatabaseInterface.h"
#include "bookLocalDatabase.h"
#include "gtest/gtest.h"

TEST(BookLocalDatabase, Add) {
    BookDataBaseInterface* db = new LocalBookStore();
    EXPECT_TRUE(db);
    Book book{"FirstBook", "12345", "Gobind Prasad", "19/12/2002"};
    db->addItem(book);

    BookPropertyTitle name{"FirstBook"};
    auto              books = db->getItemByProperty(name);
    EXPECT_EQ(books.size(), 1);

    EXPECT_EQ(books[0].getAuthor(), Author{"Gobind Prasad"});
    EXPECT_EQ(books[0].getBookId(), 1);

    db->addItem(book);
    db->addItem(book);
    db->addItem(book);
    books = db->getItemByProperty(name);
    EXPECT_EQ(books.size(), 1);
    EXPECT_EQ(books[0].getAvailableCopies(), 4);

    Book book2{"SecondBook", "1232", "Gobind Prasad", "12/01/2020"};
    db->addItem(book2);

    BookPropertyAuthor author{Author{"Gobind Prasad"}};
    books = db->getItemByProperty(author);
    std::sort(books.begin(), books.end(),
              [](const auto& book1, const auto& book2) {
                  return book1.getBookId() < book2.getBookId();
              });
    EXPECT_EQ(books.size(), 2);

    EXPECT_EQ(books[0].getAuthor(), Author{"Gobind Prasad"});
    EXPECT_EQ(books[0].getBookId(), 1);
    EXPECT_EQ(books[1].getBookId(), 2);
}

TEST(BookLocalDatabase, Remove) {
    BookDataBaseInterface* db = new LocalBookStore();
    Book book{"FirstBook", "12345", "Gobind Prasad", "19/12/2002"};
    db->addItem(book);
    db->addItem(book);

    BookPropertyTitle title{"FirstBook"};
    auto              books = db->getItemByProperty(title);
    db->removeItem(books[0]);
    books = db->getItemByProperty(title);
    EXPECT_EQ(books.size(), 1);

    db->removeItem(books[0]);
    books = db->getItemByProperty(title);
    EXPECT_EQ(books.size(), 0);

    db->addItem(book);
    Book book2{"SecondBook", "1232", "Gobind Prasad", "12/01/2020"};
    db->addItem(book2);

    BookPropertyAuthor author{Author{"Gobind Prasad"}};
    books = db->getItemByProperty(author);
    std::sort(books.begin(), books.end(),
              [](const auto& book1, const auto& book2) {
                  return book1.getBookId() < book2.getBookId();
              });
    EXPECT_EQ(books.size(), 2);
    db->removeItem(books[0]);
    db->removeItem(books[1]);
    books = db->getItemByProperty(author);
    EXPECT_EQ(books.size(), 0);
}
