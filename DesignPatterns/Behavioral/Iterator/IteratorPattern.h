#ifndef __ITERATOR_PATTERN_H__
#define __ITERATOR_PATTERN_H__

#include <initializer_list>
#include <iostream>
#include <iterator>

template <std::size_t size>
class MyArray {
public:
    class Iterator;
    // Constructors
    MyArray() { allocate(size); }
    MyArray(std::initializer_list<int> list) {
        allocate();
        // assert(list.size() <= size);
        int i = 0;
        for (auto it = list.begin(); it != list.end(); ++it) {
            m_data[i++] = *it;
        }
    }

    // Subscript operator overload, no validation
    int&       operator[](int index) { return m_data[index]; }
    const int& operator[](int index) const { return m_data[index]; }

    // Destructor
    ~MyArray() {
        if (m_data) delete[] m_data;
    }

    Iterator begin() { return Iterator(&m_data[0]); }
    Iterator end() { return Iterator(&m_data[size]); }

    // Iterator implementation for MyArray class
    class Iterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = int;
        using pointer           = int*;
        using reference         = int&;

        explicit Iterator(pointer ptr) { m_ptr = ptr; }

        // Accessor
        reference operator*() { return *m_ptr; }
        pointer   operator->() { return m_ptr; }

        // Prefix Operators
        Iterator& operator++() {
            m_ptr++;
            return *this;
        }

        // postfix Operators
        Iterator operator++(int) {
            Iterator it = *this;
            ++(*this);
            return it;
        }

        // Important compare only pointers
        friend bool operator!=(const Iterator& lhs, const Iterator& rhs) {
            return (lhs.m_ptr != rhs.m_ptr);
        }

        // Important compare only pointers
        friend bool operator==(const Iterator& lhs, const Iterator& rhs) {
            return (lhs.m_ptr == rhs.m_ptr);
        }

    private:
        pointer m_ptr{nullptr};
    };

private:
    void allocate() { m_data = new int[size]; }
    int* m_data{nullptr};
};

#endif
