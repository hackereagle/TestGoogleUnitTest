#include <iostream>
#include <gtest/gtest.h>
#include "TestSetUpConductTimes.hpp"
#include "TestValueParameterizedTests.hpp"

int myadd(int a, int b) {
    return a + b;
}

TEST(testCase, test1) {
    EXPECT_EQ(myadd(2, 3), 5);
}

int main(int argc, const char** argv)
{
	testing::InitGoogleTest(&argc, (char**)argv);
	return RUN_ALL_TESTS();
}