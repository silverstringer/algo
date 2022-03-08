#ifndef ALGO_TESTRANGE_H
#define ALGO_TESTRANGE_H

#include <math.h>
#include <gtest/gtest.h>
#include <gtest/gtest_prod.h>
#include <gmock/gmock-matchers.h>

#include "RangeSEQ.h"


/**
 * @brief Simple class to test
 */

class TestPacket : public ::testing::Test {
public:

protected:
    virtual void SetUp() {

    }

    virtual void TearDown() {

    }
};

TEST_F (TestPacket, RangeSEQ) {


    std::vector<int> seq { 2, 11, 2, 4, 16, 11, 20, 5, 11, 4, 19, 17, 18 };

    auto sum_of_elems = std::accumulate(seq.rbegin(), seq.rend(), 0);

    constexpr int sum_bande = 22;

    RangeSeq <std::vector<int>> seq_rang;

    ASSERT_GE(sum_of_elems, sum_bande);

    auto range = seq_rang.make_range_seq(seq, sum_bande);

    for(std::map<int, int >::iterator it = range.begin();
        it != range.end(); ++it)
    {
        auto sum {0};
        sum = seq_rang.sum_seq(seq, it->first, it->second + 1);
        ASSERT_LE( sum, sum_bande);
    }
}

TEST_F (TestPacket, RangeSEQList) {


    std::list<int> seq { 1, 10, 12, 4, 19, 7, 31, 5, 15, 2, 19, 17, 18,24 };

    auto sum_of_elems = std::accumulate(seq.rbegin(), seq.rend(), 0);

    constexpr int sum_bande = 25;

    RangeSeq <std::list<int>> seq_range;

    ASSERT_GE(sum_of_elems, sum_bande);

    auto range = seq_range.make_range_seq(seq, 25);

    for(auto it = range.begin();
        it != range.end(); ++it)
    {
        auto sum {0};
        sum = seq_range.sum_seq(seq, it->first, it->second + 1);
        ASSERT_LE( sum, sum_bande);
    }
}

#endif //ALGO_TESTRANGE_H
