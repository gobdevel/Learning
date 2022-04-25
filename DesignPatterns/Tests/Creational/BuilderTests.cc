#include "BuilderPattern.h"
#include "gtest/gtest.h"

TEST(Builder, Simple) {
    HtmlElement e = HtmlElement::build("ul")
                        ->addChild("li", "hello")
                        .addChild("li", "world");

    Person p = Person::create()
                   ->lives()
                   .at("123 Road")
                   .city("Sunnyvale")
                   .pin("123456")
                   .works()
                   .at("Juniper")
                   .as_a("Staff Software Engineer")
                   .earning(10000000000);
    EXPECT_TRUE(true);
}
