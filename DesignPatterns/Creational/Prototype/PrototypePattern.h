#ifndef __PROTOTYPE_PATTERN_H__
#define __PROTOTYPE_PATTERN_H__

#include <string>

// Create objects from already created objects and modify only parameter
// according to new object need.
constexpr const static int SIZE = 128;

class Address {
public:
    Address() = default;
    Address(std::string name, char *address)
        : m_name(std::move(name)), m_address(address) {}

    // Copy Constructor
    Address(const Address &other) {
        m_name    = other.m_name;
        m_address = new char[SIZE];
        memcpy(m_address, other.m_address, SIZE);
    }

    Address &operator=(const Address &other) {
        m_name    = other.m_name;
        m_address = new char[SIZE];
        memcpy(m_address, other.m_address, SIZE);
        return *this;
    }

    virtual Address *clone() { return new Address(*this); }

private:
    std::string m_name;
    char       *m_address;
};

class ExtendedAddress : public Address {
public:
    ExtendedAddress(std::string country, std::string name, char *address)
        : Address(name, address), m_country(std::move(country)) {}

    // Copy Constructor
    ExtendedAddress(const ExtendedAddress &other)
        : Address(*this), m_country(other.m_country) {}

    ExtendedAddress *clone() override { return new ExtendedAddress(*this); }

private:
    std::string m_country;
};

/**
 *  How will you copy from base class refrence
 *  Address *adr = new ExtendedAddress("India", "Gobind", ptr);
 *  Address newAdr = adr;  // Will copy only Adress not ExtendedAddress
 *  WITH CLONE VIRTUAL METHOD AND DEEP COPY THIS CAN BE DONE
 */
#endif
