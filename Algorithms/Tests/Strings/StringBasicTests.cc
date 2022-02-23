#include "StringBasics.h"
#include "gtest/gtest.h"

TEST(StringBasics, Spaces) {
    std::vector<char> str1{' '};
    str1.resize(3);
    std::vector<char> str11{'%', '2', '0'};

    std::vector<char> str2{'H', ' ', ' ', 'Y'};
    str2.resize(8);
    std::vector<char> str22{'H', '%', '2', '0', '%', '2', '0', 'Y'};

    std::vector<char> str3{'H', ' '};
    str3.resize(4);
    std::vector<char> str33{'H', '%', '2', '0'};

    std::vector<char> str4{'H', 'I', ' ', 'N', 'O'};
    str4.resize(7);
    std::vector<char> str44{'H', 'I', '%', '2', '0', 'N', 'O'};

    replaceSpaces(str1, 1);
    EXPECT_EQ(str1, str11);
    replaceSpaces(str2, 4);
    EXPECT_EQ(str2, str22);
    replaceSpaces(str3, 2);
    EXPECT_EQ(str3, str33);
    replaceSpaces(str4, 5);
    EXPECT_EQ(str4, str44);
}

TEST(StringBasics, Subset) {
    std::string s1("abde"), s2("abbcdteee");
    EXPECT_TRUE(isSubset(s1, s2));

    s1 = "";
    s2 = "Hellow World";
    EXPECT_FALSE(isSubset(s1, s2));

    s1 = "a";
    s2 = "Hellow Worlda";
    EXPECT_TRUE(isSubset(s1, s2));
}
