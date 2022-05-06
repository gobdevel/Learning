#include "DecoratorPattern.h"
#include "gtest/gtest.h"

TEST(Decorator, Dynamic) {
    Circle       circle{10};
    ColoredShape redCircle{circle, "red"};

    EXPECT_EQ(redCircle.str(), "Circle red");

    redCircle.makeDark();
    EXPECT_EQ(redCircle.str(), "Circle dark");

    TransparentShape transparentShape(circle, 2);
    EXPECT_EQ(transparentShape.str(), "Circle Transparent");

    TransparentShape transparentShape2(redCircle, 2);
    EXPECT_EQ(transparentShape2.str(), "Circle dark Transparent");
}

TEST(Decorator, Static) {
    ColoredShape2<Circle> redCircle("red", 10);
    EXPECT_EQ(redCircle.str(), "Circle red");

    ColoredShape2<TransparentShape2<Circle>> transparentRedCircle("red", 2, 10);
    EXPECT_EQ(transparentRedCircle.str(), "Circle Transparent red");
}
