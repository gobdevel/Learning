#include "Singleton.h"
#include "gtest/gtest.h"

class TestSingleton : public Singleton<TestSingleton> {
    friend SingletonDerive;

public:
    int getInstanceCount() { return s_instanceCount; }

private:
    TestSingleton() { s_instanceCount++; }
    static int s_instanceCount;
};

int TestSingleton::s_instanceCount = 0;

TEST(Singleton, Singleton) {
    auto& t = TestSingleton::getInstance();
    EXPECT_EQ(t.getInstanceCount(), 1);

    auto& t2 = TestSingleton::getInstance();
    EXPECT_EQ(t2.getInstanceCount(), 1);
}
