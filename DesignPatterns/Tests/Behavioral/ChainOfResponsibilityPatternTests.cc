#include "ChainOfResponsibilityPattern.h"
#include "gtest/gtest.h"

TEST(ChainOfResponsibility, Simple) {
    AdditionChain       add;
    SubtractionChain    sub;
    MultiplicationChain mul;
    DivisionChain       div;

    Chain *chain = &add;
    add.addNextInChain(&sub);
    sub.addNextInChain(&mul);
    mul.addNextInChain(&div);

    Numbers nums{4, 2};

    EXPECT_EQ(chain->process(nums, Operation::add), 6);
    EXPECT_EQ(chain->process(nums, Operation::mult), 8);
    EXPECT_EQ(chain->process(nums, Operation::pow), -1);
}
