#pragma once

#include <string>

class User {
public:
    User() : m_id(++s_id) {}
    User(std::string name, std::string address)
        : m_id(++s_id),
          m_name(std::move(name)),
          m_address(std::move(address)) {}

    virtual ~User() {}

    std::uint32_t getId() const { return m_id; }
    std::uint32_t getId() { return m_id; }

    template <typename T>
    void setName(T&& name) {
        m_name = std::forward<T>(name);
    }

    std::string getName() const { return m_name; }
    std::string getAddress() const { return m_address; }

    template <typename T>
    void setAddress(T&& address) {
        m_address = std::forward<T>(address);
    }

private:
    // Static Data Members
    static std::uint32_t s_id;

    // Class Members
    std::uint32_t m_id;
    std::string   m_name;
    std::string   m_address;
};
