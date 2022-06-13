#pragma once

#include <iostream>

#include "bookDatabaseInterface.h"
#include "dbInterface.h"

class SystemNotifier : public Observer<Book> {
public:
    void fieldChanged(const Book &book, const std::string &fieldName) override {
        // notify Users for this book
        if (fieldName.compare("Availale") == 0) {
            for (const auto &email : m_users) {
                std::cout << "Sending mail to " << email << " Book "
                          << book.getTitle() << " is now available\n";
            }
        }
    }

private:
    using UserEmails   = std::vector<std::string>;
    using WaitingUsers = std::unordered_map<BookId, UserEmails>;
    WaitingUsers m_users;
};
