#pragma once

#include <iostream>
#include <gtest/gtest.h>

static int SetUpCount = 0;

class TestSetUpConductTimes : public ::testing::Test
{
public:
	virtual void SetUp() override
	{
		SetUpCount++;
	}

	virtual void TearDown() override
	{

	}
};

TEST_F(TestSetUpConductTimes, TestCase1)
{
	EXPECT_EQ(SetUpCount, 1);
}

TEST_F(TestSetUpConductTimes, TestCase2)
{
	EXPECT_EQ(SetUpCount, 2);
}

// ========== Method 2 ==========
// Although in documentation, https://google.github.io/googletest/advanced.html#sharing-resources-between-tests-in-the-same-test-suite, say that SetUpTestSuite and TearDownTestSuite
// may be called not only once, I tested result is that both static method only be called once.
// But I still need to be careful!
static int StaticSetupCount = 0;
class TestSetUpConductTimesByStaticSetUp : public ::testing::Test
{
protected:
	static void SetUpTestSuite()
	{
		StaticSetupCount++;
	}

	static void TearDownTestSuite()  
	{

	}
};

TEST_F(TestSetUpConductTimesByStaticSetUp, TestCase1)
{
	EXPECT_EQ(StaticSetupCount, 1);
}

TEST_F(TestSetUpConductTimesByStaticSetUp, TestCase2)
{
	EXPECT_EQ(StaticSetupCount, 1);
}

// ========== Method 3 ==========
// Using enviroment
// Please refer to https://google.github.io/googletest/advanced.html#global-set-up-and-tear-down
// It is for entire testing. It seems me to that it is not my ideal method, so I will test later.