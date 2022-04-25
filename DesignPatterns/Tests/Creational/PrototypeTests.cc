#include "PrototypePattern.h"
#include "gtest/gtest.h"

TEST(Prototype, Simple) {
    char    *ptr    = new char[SIZE];
    Address *adr    = new ExtendedAddress("India", "Gobind", ptr);
    Address *newAdr = adr->clone();
    EXPECT_TRUE(newAdr);
}
