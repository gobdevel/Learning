#ifndef __BASIC_PATTERNS_H__
#define __BASIC_PATTERNS_H__
#include <iostream>
#include <typeinfo>

namespace CRTP {
/**
 *  Curiously Recurring Template Patterns (CRTP)
 *  If you want to work on dervied class object from Base class without dynamic
 *  polymorphism, you can pass derived class type as template parameter in Base
 *  class then typecast base class this pointer with template type and use.
 *  This allows to move common functionalities to Base class.
 *  You can also tell this allows Base class to have functionalities of derived
 *  class. (other way around)
 */

template <typename Derived>
class Base {
public:
    void printType() { std::cout << typeid(Derived).name() << "\n"; }
    void magic() { static_cast<Derived&>(*this).magic(); }
};

class Derived1 : public Base<Derived1> {
public:
    void magic() { std::cout << __PRETTY_FUNCTION__ << "\n"; }
};

class Derived2 : public Base<Derived2> {
public:
    void magic() { std::cout << __PRETTY_FUNCTION__ << "\n"; }
};

template <typename T>
void print(Base<T>& base) {
    base.printType();
}

}  // namespace CRTP

namespace Mixin {
/**
 * Mixin Inheritence
 * In C++, a class can be defined to inherit from its own template argument.
 * This approach is called Mixin inheritence and allows hierarchical composition
 * of types - Foo<Bar<Baz>> x;
 */

template <typename T>
class Foo : public T {
public:
    void foo() {}
};

template <typename T>
class Bar : public T {
public:
    void bar() {}
};

class Baz {
public:
    void baz() {}
};

}  // namespace Mixin

#endif
