#include "gtest/gtest.h"
#include "visitorPattern.h"

using namespace VisitorPattern;

TEST(VisitorPattern, Basic) {
    auto pe = new PermanentEmployee();
    auto te = new TempEmployee();

    EmployeePrinter p;
    p.visit(pe);
    p.visit(te);

    EmployeeNotifier n;
    n.visit(pe);
    n.visit(te);

    EXPECT_TRUE(true);
}
