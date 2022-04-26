#ifndef __USER_H__
#define __USER_H__
#include <string>

class User {
public:
    User() = default;
    User(std::uint32_t id) : m_id(id) {}
    User(std::uint32_t id, std::string name, std::string address)
        : m_id(id), m_name(std::move(name)), m_address(std::move(address)) {}

    void          setId(std::uint32_t id) { m_id = id; }
    std::uint32_t getId() const { return m_id; }
    std::uint32_t getId() { return m_id; }

    template <typename T>
    void setName(T&& name) {
        m_name = std::forward<T>(name);
    }

    std::string getName() { return m_name; }
    std::string getAddress() { return m_address; }

    template <typename T>
    void setAddress(T&& address) {
        m_address = std::forward<T>(address);
    }

private:
    std::uint32_t m_id;
    std::string   m_name;
    std::string   m_address;
};

#endif
