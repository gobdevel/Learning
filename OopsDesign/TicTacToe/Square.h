#ifndef __SQUARE_H__
#define __SQUARE_H__
#include <algorithm>

#include "Location.h"

enum class Marker { empty, p1, p2 };

class Square {
public:
    Square(Location loc) : m_loc(std::move(loc)) {}

    template <typename T>
    void setLocation(T&& loc) {
        m_loc = std::move(loc);
    }

    void   setMarker(Marker m) { m_marker = m; }
    Marker getMarker() { return m_marker; }

    friend bool operator==(const Square& lhs, const Square& rhs) {
        return (lhs.m_marker == rhs.m_marker);
    }

    friend bool operator!=(const Square& lhs, const Square& rhs) {
        return (lhs.m_marker != rhs.m_marker);
    }

    // const Location& getLocation() { return m_loc; }
    bool isEmpty() { return m_marker == Marker::empty; }

private:
    Location m_loc;
    Marker   m_marker{Marker::empty};
};

#endif
