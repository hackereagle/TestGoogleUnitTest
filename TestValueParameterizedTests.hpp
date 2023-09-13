#pragma once

#include <iostream>
#include <gtest/gtest.h>

// Test parameters are variable instead of array.
/*
This will occur 
*/
inline int Add(int a, int b)
{
	return a + b;
}

typedef struct testParameterized1Params
{
	int A = 0;
	int B = 0;
	int Expected = 0;

	testParameterized1Params(int a, int b, int expectecd) : A(a), B(b), Expected(expectecd) {}
}TestParameterized1Params;

class TestParameterized1 : public ::testing::TestWithParam<TestParameterized1Params> 
{
public:
	TestParameterized1() {}
	~TestParameterized1() override {}

	void SetUp() override {
		// Can use GetParam() here.
	}
	void TearDown() override {
		// Can use GetParam() here.
	}
};

TEST_P(TestParameterized1, TestVariables)
{
	// ARRANG
	TestParameterized1Params params = GetParam();
	int a = params.A;
	int b = params.B;
	int expected = params.Expected;

	// ACT
	int result = Add(a, b);

	// ASSERT
	EXPECT_EQ(expected, result);
}

INSTANTIATE_TEST_SUITE_P(TestParameterized1_TestData, TestParameterized1, 
						::testing::Values(
							TestParameterized1Params{1, 2, 3},
							TestParameterized1Params{4, 2, 6}
						));

// Test pass struct which have array.
/*
This will occur ERROR:
testgoogleunittest/TestValueParameterizedTests.hpp:121:8: error: no matching constructor for initialization of 'testParameterized2Params'
                                                        testParameterized2Params({{1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, 1}),
                                                        ^                        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
/*typedef struct resultStruct
{
	int X = 0;
	int Y = 0;

	resultStruct() = default;
	resultStruct(int x, int y) : X(x), Y(y) {}
	bool operator==(const resultStruct &r)
	{
		return this->X == r.X && this->Y == r.Y;
	}

	friend bool operator==(const resultStruct &l, const resultStruct &r)
	{
		return l.X == r.X && l.Y == r.Y;
	}
}ResultStruct;

inline ResultStruct DoSomeAlgorithm(int param1, double param2, int type)
{
	ResultStruct ret;
	ret.X = param1;
	ret.Y = static_cast<int>(param2 * 10) + param1 + type;
	return ret;
}

typedef struct testParameterized2Params
{
	int IParam[10] {0};
	double DParam[10] {0.0};
	int Type = 0;

	testParameterized2Params() = default;
	testParameterized2Params(int* a, double* b, int type) 
	{
		memcpy(IParam, a, sizeof(int) * 10);
		memcpy(DParam, b, sizeof(double) * 10);
	}
}TestParameterized2Params;

class TestParameterizedWithStruct : public ::testing::TestWithParam<TestParameterized2Params> {};

TEST_P(TestParameterizedWithStruct, TestStructHaveArray)
{
	// ARRANGE
	auto params = GetParam();
	int param1 = params.IParam[0];
	double param2 = params.DParam[0];
	int type = params.Type;
	ResultStruct expected(param1, static_cast<int>(param2 * 10) + param1 + type);

	// ACT
	ResultStruct result = DoSomeAlgorithm(param1, param2, type);

	// ASSERT
	EXPECT_EQ(expected, result);
}

// INSTANTIATE_TEST_SUITE_P(TestParameterized2_TestData, TestParameterizedWithStruct, 
// 						::testing::Values(
// 							TestParameterized2Params{{1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, 1},
// 							TestParameterized2Params{{2, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {30.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, 1}
// 						));
INSTANTIATE_TEST_SUITE_P(TestParameterized2_TestData, TestParameterizedWithStruct, 
						::testing::Values(
							testParameterized2Params({{1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, 1}),
							testParameterized2Params({{2, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {30.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, 1})
						));
*/