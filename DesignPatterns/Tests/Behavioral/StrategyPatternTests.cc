#include "StrategyPattern.h"
#include "gtest/gtest.h"

TEST(StrategyPattern, Dynamic) {
    std::string str{"GOBIND"};

    PrinterStrategy *s = new SmallLetterStrategy();
    Printer          p(*s);
    p.print(str);

    PrinterStrategy *c = new CapitalLetterStrategy();
    Printer          p1(*c);
    p1.print(str);
    EXPECT_TRUE(true);
}

TEST(StrategyPattern, Static) {
    std::string str{"GOBIND"};

    StaticPrinter<SmallLetterStrategy> p;
    p.print(str);

    StaticPrinter<CapitalLetterStrategy> p1;
    p1.print(str);
    EXPECT_TRUE(true);
}
