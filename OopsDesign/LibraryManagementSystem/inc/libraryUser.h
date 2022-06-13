#pragma once
#include "library.h"
#include "user.h"

template <typename... T>
class LibraryUser : public User, public T... {
protected:
    enum class Type { Member, Librarian, System };
    LibraryUser(Type type, std::string name, std::string address)
        : User(std::move(name), std::move(address)), m_type(type) {}

private:
    Type m_type;
};

class Member : public LibraryUser<BookSearch, BookTransaction> {
public:
    Member(std::string name, std::string address)
        : LibraryUser(Type::Member, std::move(name), std::move(address)) {}
};

class Librarian
    : public LibraryUser<BookSearch, ManageLibrary, BookTransaction> {
public:
    Librarian(std::string name, std::string address)
        : LibraryUser(Type::Librarian, std::move(name), std::move(address)) {}
};
