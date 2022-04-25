#ifndef __BUILDER_PATTERN_H__
#define __BUILDER_PATTERN_H__

#include <memory>
#include <ostream>
#include <string>
#include <vector>

class FluentBuilder;

// If an object of a class can not be created in simple one line, It needed
// multiple pieces to build the whole class

class HtmlElement {
public:
    HtmlElement() = default;
    HtmlElement(std::string name, std::string text)
        : m_name(std::move(name)), m_text(std::move(text)) {}

    void emplace(HtmlElement element) {
        m_elements.emplace_back(std::move(element));
    }

    static std::unique_ptr<FluentBuilder> build(std::string rootName) {
        return std::make_unique<FluentBuilder>(std::move(rootName));
    }
    std::string str() {
        std::string htmlString;
        // Pretty print html elements
        return htmlString;
    }

private:
    std::string              m_name;
    std::string              m_text;
    std::vector<HtmlElement> m_elements;
};

/*
 * Template - 1 Simple Builer
 */

class SimpleBuilder {
public:
    explicit SimpleBuilder(std::string rootName) noexcept
        : m_root(std::move(rootName), "") {}

    void addChild(std::string name, std::string text) {
        m_root.emplace(HtmlElement(std::move(name), std::move(text)));
    }

    std::string str() { return m_root.str(); }

private:
    HtmlElement m_root;
};

/**
 * Template - 2 Fluent builder
 * Return this pointer to chain the building process
 */

class FluentBuilder {
public:
    explicit FluentBuilder(std::string rootName) noexcept
        : m_root(std::move(rootName), "") {}

    FluentBuilder& addChild(std::string name, std::string text) {
        m_root.emplace(HtmlElement(std::move(name), std::move(text)));
        return *this;
    }

    std::string str() { return m_root.str(); }

    // This operator will be used in Template - 3
    operator HtmlElement() const { return m_root; }

private:
    HtmlElement m_root;
};

/**
 * Usage Example
 * HtmlElement e =
 *   HtmlElement::build("ul")->addChild("li", "hello").addChild("li", "world");
 */

/**
 * Composite builder
 */

class PersonBuilder;
class PersonJobBuilder;
class PersonAddressBuilder;

class Person {
public:
    static std::unique_ptr<PersonBuilder> create() {
        return std::make_unique<PersonBuilder>();
    }

private:
    Person() = default;
    // Address
    std::string street, pin, city;

    // Employment
    std::string company, position;
    uint64_t    salary;

    friend class PersonBuilder;
    friend class PersonJobBuilder;
    friend class PersonAddressBuilder;
};

class PersonBuilderBase {
protected:
    Person& m_p;
    explicit PersonBuilderBase(Person& p) : m_p(p) {}

public:
    operator Person() { return std::move(m_p); }

    // Builder facets
    PersonAddressBuilder lives() const;
    PersonJobBuilder     works() const;
};

class PersonAddressBuilder : public PersonBuilderBase {
public:
    explicit PersonAddressBuilder(Person& p) : PersonBuilderBase(p) {}
    PersonAddressBuilder& at(std::string street) {
        m_p.street = street;
        return *this;
    }

    PersonAddressBuilder& pin(std::string pin) {
        m_p.pin = pin;
        return *this;
    }

    PersonAddressBuilder& city(std::string city) {
        m_p.pin = city;
        return *this;
    }
};

class PersonJobBuilder : public PersonBuilderBase {
public:
    explicit PersonJobBuilder(Person& p) : PersonBuilderBase(p) {}
    PersonJobBuilder& at(std::string company) {
        m_p.company = company;
        return *this;
    }

    PersonJobBuilder& as_a(std::string position) {
        m_p.position = position;
        return *this;
    }

    PersonJobBuilder& earning(uint64_t salary) {
        m_p.salary = salary;
        return *this;
    }
};

PersonAddressBuilder PersonBuilderBase::lives() const {
    return PersonAddressBuilder(m_p);
};

PersonJobBuilder PersonBuilderBase::works() const {
    return PersonJobBuilder(m_p);
};

class PersonBuilder : public PersonBuilderBase {
public:
    PersonBuilder() : PersonBuilderBase{p} {}

private:
    Person p;
};

#endif
