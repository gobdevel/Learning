#ifndef __DECORATOR_PATTERN_H__
#define __DECORATOR_PATTERN_H__

#include <string>
#include <type_traits>

// An Interface for Shape
struct Shape {
    virtual std::string str() = 0;
};

// A Circle Class implementing Shape
struct Circle : Shape {
    int m_radius;
    explicit Circle(int radius) : m_radius(radius) {}

    std::string str() override { return "Circle"; }
};

/**
 *  Type 1 - Dynamic Decorator
 *  Create another Class inherting from interface with new property
 *  and have Circle as member variable.
 */

struct ColoredShape : Shape {
    Shape&      m_shape;
    std::string m_color;
    ColoredShape(Shape& shape, std::string color)
        : m_shape(shape), m_color(color) {}

    // Adding color property to any shape
    std::string str() override { return m_shape.str() + " " + m_color; }

    // Having extra property only for ColoredShape
    void makeDark() { m_color = "dark"; }
};

struct TransparentShape : Shape {
    Shape& m_shape;
    int    m_transparency;
    TransparentShape(Shape& shape, int transparency)
        : m_shape(shape), m_transparency(transparency) {}

    std::string str() override { return (m_shape.str() + " Transparent"); }
};

/**
 *  Type 2 - Static/Templated Decorator
 *  Create another Class inherting from interface with new property
 *  and have Circle as member variable.
 */

template <typename T>
struct ColoredShape2 : T {
    std::string m_color;
    template <typename... Args>
    ColoredShape2(std::string color, Args... args)
        : T(std::forward<Args>(args)...), m_color(color) {
        static_assert(std::is_base_of_v<Shape, T>,
                      "Template Argument must be a Shape");
    }

    std::string str() override { return (T::str() + " " + m_color); }
};

template <typename T>
struct TransparentShape2 : T {
    int m_transparency;
    template <typename... Args>
    TransparentShape2(int transparency, Args... args)
        : T(std::forward<Args>(args)...), m_transparency(transparency) {
        static_assert(std::is_base_of_v<Shape, T>,
                      "Template Argument must be a Shape");
    }

    std::string str() override { return (T::str() + " Transparent"); }
};

#endif
