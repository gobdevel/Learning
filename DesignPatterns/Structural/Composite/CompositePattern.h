#ifndef __COMPOSITE_PATTERN_H__
#define __COMPOSITE_PATTERN_H__
#include "utils.h"

namespace CompositePattern {

/**
 *  Scalar class object interface can behave as composite/Group.
 */

struct GraphicObject {
    virtual Nums draw() = 0;
};

struct Circle : GraphicObject {
    int m_id{0};

    Circle(int id) : m_id(id) {}

    Nums draw() override { return {m_id}; }
};

struct Group : GraphicObject {
    int                         m_id;
    std::vector<GraphicObject*> m_objects;

    Group(int id) : m_id(id) {}

    Nums draw() override {
        Nums out;
        out.emplace_back(m_id);

        for (auto& o : m_objects) {
            auto vec = o->draw();
            for (auto& v : vec) {
                out.emplace_back(v);
            }
        }

        return out;
    }
};

}  // namespace CompositePattern

#endif
