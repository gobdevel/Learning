#include "MergeIntervals.h"
#include "gtest/gtest.h"

TEST(MergeInterval, MutualExclusive) {
    Intervals input{
        {6, 7},
        {2, 4},
        {5, 9}
    };
    Intervals answer{
        {2, 4},
        {5, 9}
    };

    auto ret = findMutualExclusiveIntervals(input);
    EXPECT_EQ(ret, answer);
}

TEST(MergeInterval, MutualExclusiveSingle) {
    Intervals input{
        {6, 7}
    };
    Intervals answer{
        {6, 7}
    };

    auto ret = findMutualExclusiveIntervals(input);
    EXPECT_EQ(ret, answer);
}

TEST(MergeInterval, MutualExclusiveAll) {
    Intervals input{
        {1, 4},
        {2, 6},
        {3, 5}
    };
    Intervals answer{
        {1, 6}
    };

    auto ret = findMutualExclusiveIntervals(input);
    EXPECT_EQ(ret, answer);
}

TEST(MergeInterval, Insert) {
    Intervals input{
        {1, 3 },
        {5, 7 },
        {8, 12}
    };
    Intervals answer{
        {1, 3 },
        {4, 7 },
        {8, 12}
    };

    auto ret = InsertInSortedIntervalsAndMerge(input, {4, 6});
    EXPECT_EQ(ret, answer);
}

TEST(MergeInterval, Insert2) {
    Intervals input{
        {1, 3 },
        {5, 7 },
        {8, 12}
    };
    Intervals answer{
        {1, 3 },
        {4, 12}
    };

    auto ret = InsertInSortedIntervalsAndMerge(input, {4, 10});
    EXPECT_EQ(ret, answer);
}

TEST(MergeInterval, Insert3) {
    Intervals input{
        {1, 3 },
        {5, 7 },
        {8, 12}
    };
    Intervals answer{
        {1,  3 },
        {5,  7 },
        {8,  12},
        {14, 18}
    };

    auto ret = InsertInSortedIntervalsAndMerge(input, {14, 18});
    EXPECT_EQ(ret, answer);
}

TEST(MergeInterval, Insert4) {
    Intervals input{
        {1, 3 },
        {5, 7 },
        {8, 12}
    };
    Intervals answer{
        {1, 20}
    };

    auto ret = InsertInSortedIntervalsAndMerge(input, {1, 20});
    EXPECT_EQ(ret, answer);
}

TEST(MergeInterval, DisjointIntersection) {
    Intervals input1{
        {1, 3},
        {5, 6},
        {7, 9}
    };
    Intervals input2{
        {2, 3},
        {5, 7}
    };
    Intervals answer{
        {2, 3},
        {5, 6},
        {7, 7}
    };

    auto ret = findDisjointIntervalIntersections(input1, input2);
    EXPECT_EQ(ret, answer);
}
