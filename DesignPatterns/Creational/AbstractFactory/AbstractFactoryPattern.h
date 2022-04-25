#ifndef __ABSTRACT_FACTORY_PATTERN_H__
#define __ABSTRACT_FACTORY_PATTERN_H__

#include <iostream>

class Product {
public:
    virtual void operation() = 0;
};

class ProductA : public Product {
public:
    void operation() override final {
        std::cout << __PRETTY_FUNCTION__ << "\n";
    }
};

class ProductB : public Product {
public:
    void operation() override final {
        std::cout << __PRETTY_FUNCTION__ << "\n";
    }
};

using ProductId = int;

class AbstractFactory {
public:
    virtual Product* createProduct(ProductId id) = 0;
};

class ConcreateFactoryA : public AbstractFactory {
public:
    Product* createProduct(ProductId id) override {
        Product* p = nullptr;
        if (id == 0) {
            p = new ProductA();
        } else {
            p = new ProductB();
        }
        return p;
    }
};

// A little different Product than A and B
class ProductC : public Product {
public:
    void operation() override final {
        std::cout << __PRETTY_FUNCTION__ << "\n";
    }
};

class ProductD : public Product {
public:
    void operation() override final {
        std::cout << __PRETTY_FUNCTION__ << "\n";
    }
};

class ConcreateFactoryB : public AbstractFactory {
public:
    Product* createProduct(ProductId id) override {
        Product* p = nullptr;
        if (id == 0) {
            p = new ProductC();
        } else {
            p = new ProductD();
        }
        return p;
    }
};

// Actor
class Creator {
public:
    static Product* createProduct(AbstractFactory& factory, ProductId id) {
        return factory.createProduct(id);
    }
};

#endif
