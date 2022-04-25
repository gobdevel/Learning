#ifndef __FACTORY_PATTERN_H__
#define __FACTORY_PATTERN_H__
#include <iostream>

class Product {
public:
    virtual void operation() = 0;
};

class ProductA : public Product {
public:
    void operation() override { std::cout << __PRETTY_FUNCTION__ << "\n"; }
};

class ProductB : public Product {
public:
    void operation() override { std::cout << __PRETTY_FUNCTION__ << "\n"; }
};

// Factory Method Type 1, Using polymorphism.
//--------------------------------------------
class Creator {
public:
    virtual Product* create() = 0;
};

class ProductACreator : public Creator {
public:
    Product* create() override { return new ProductA(); }
};

class ProductBCreator : public Creator {
public:
    Product* create() override { return new ProductB(); }
};

// Factory Method Type 2, Parameterised creator.
//--------------------------------------------
using ProductId = int;

class ParamterizedCreator {
public:
    virtual Product* create(ProductId id) {
        Product* p = nullptr;
        if (id == 0) {
            p = new ProductA();
        } else {
            p = new ProductB();
        }
        return p;
    }
};

// Factory Method Type 3, Templated Creator.
//--------------------------------------------
class TemplatedCreator {
public:
    virtual Product* create() = 0;
};

template <typename T>
class ProductCreator : public TemplatedCreator {
public:
    Product* create() override { return new T(); }
};

#endif
