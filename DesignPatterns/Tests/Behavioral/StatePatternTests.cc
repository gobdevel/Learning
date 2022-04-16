#include "StatePattern.h"
#include "gtest/gtest.h"

TEST(StatePattern, Basic) {
    Session s;
    EXPECT_EQ(s.getStateId(), StateId::Init);

    s.configured();
    EXPECT_EQ(s.getStateId(), StateId::Configured);

    s.configured();
    EXPECT_EQ(s.getStateId(), StateId::Configured);

    s.active();
    EXPECT_EQ(s.getStateId(), StateId::Active);

    s.terminating();
    EXPECT_EQ(s.getStateId(), StateId::Terminating);

    s.terminating();
    EXPECT_EQ(s.getStateId(), StateId::Terminating);

    s.terminated();
    EXPECT_EQ(s.getStateId(), StateId::Terminated);

    s.init();
    EXPECT_EQ(s.getStateId(), StateId::Terminated);
}
