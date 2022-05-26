#ifndef __BRIDGE_PATTERN_H__
#define __BRIDGE_PATTERN_H__

namespace BridgePattern {

struct DrawingApi {
    virtual int drawCircle() = 0;
};

struct DrawingApi_1 : DrawingApi {
    int drawCircle() override { return 1; }
};

struct DrawingApi_2 : DrawingApi {
    int drawCircle() override { return 2; }
};

struct Shape {
    Shape(DrawingApi *bridge) : m_brdige(bridge) {}
    virtual int draw() = 0;

protected:
    DrawingApi *m_brdige;
};

struct Circle : Shape {
    Circle(DrawingApi *bridge) : Shape(bridge) {}
    int draw() override { return m_brdige->drawCircle(); }
};

}  // namespace BridgePattern
#endif
