#include "AbstractFactoryPattern.h"
#include "gtest/gtest.h"

TEST(AbstractFactory, Simple) {
    ConcreateFactoryA cfa;
    ConcreateFactoryB cfb;
    Creator::createProduct(cfa, 0)->operation();
    Creator::createProduct(cfa, 1)->operation();
    Creator::createProduct(cfb, 0)->operation();
    Creator::createProduct(cfb, 1)->operation();
}
