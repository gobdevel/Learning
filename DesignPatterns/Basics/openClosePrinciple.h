#pragma once

#include <string>
#include <vector>

namespace OCP {

enum class Color { Red, Green, Blue };
enum class Size { Small, Medium, Big };

struct Product {
    explicit Product(std::string name, Color color, Size size)
        : name(name), color(color), size(size) {}
    std::string name;
    Color       color;
    Size        size;
};

template <typename T>
struct Specification {  // Predicate
    virtual bool isSatisfied(const T& item) = 0;
};

template <typename T>
struct Filter {
    virtual std::vector<T*> filter(std::vector<T*>   items,
                                   Specification<T>& spec) const = 0;
};

struct BetterFilter : Filter<Product> {
    std::vector<Product*> filter(std::vector<Product*>   items,
                                 Specification<Product>& spec) const override {
        std::vector<Product*> result;
        for (const auto& i : items) {
            if (spec.isSatisfied(*i)) {
                result.push_back(i);
            }
        }
        return result;
    }
};

struct ColorSpecification : Specification<Product> {
    Color color;
    explicit ColorSpecification(const Color color) : color(color) {}
    bool isSatisfied(const Product& p) override { return (p.color == color); }
};

struct SizeSpecification : Specification<Product> {
    Size size;
    explicit SizeSpecification(const Size size) : size(size) {}
    bool isSatisfied(const Product& p) override { return (p.size == size); }
};

}  // namespace OCP
