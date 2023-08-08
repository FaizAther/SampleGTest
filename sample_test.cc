#include <gtest/gtest.h>

#include "factorial.hh"
#include "fib.hh"
#include <deque>

#include <gmock/gmock-matchers.h>

using ::testing::HasSubstr;
using ::testing::MatchesRegex;

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);

  EXPECT_EQ(7 * 6, 42);
}

// Tests factorial of positive numbers.
TEST(FactorialTest, HandlesPositiveInput) {
  EXPECT_EQ(Factorial(1), 1);
  EXPECT_EQ(Factorial(2), 2);
  EXPECT_EQ(Factorial(3), 6);
  EXPECT_EQ(Factorial(8), 40320);
  EXPECT_NE(Factorial(8), 40321);
}

class DequeTest : public ::testing::Test {
  protected:
    void SetUp() override {
      // q0_ remains empty
      q1_.push_back(1);
      q2_.push_back(2);
      q3_.push_back(3);
    }
    // void TearDown() override {} not required
    std::deque<int> q0_;
    std::deque<int> q1_;
    std::deque<int> q2_;
    std::deque<int> q3_;
};

TEST_F(DequeTest, isEmptyInitially)
{
  EXPECT_EQ(q0_.size(), 0);
}

TEST_F(DequeTest, DequeWorks) {
  std::deque<int>::iterator n = q0_.begin();
  EXPECT_EQ(n, q0_.end());

  n = (q1_.begin());
  ASSERT_NE(n, q1_.end());
  EXPECT_EQ(*n, 1);

  EXPECT_EQ(q1_.size(), 1);
  q1_.pop_back();
  EXPECT_EQ(q1_.size(), 0);

  n = (q2_.begin());
  ASSERT_NE(n, q2_.end());
  EXPECT_EQ(*n, 2);

  EXPECT_EQ(q2_.size(), 1);
  q2_.pop_back();
  EXPECT_EQ(q2_.size(), 0);
}

testing::AssertionResult IsEven(int n) {
  if ((n % 2) == 0)
    return testing::AssertionSuccess() << n << " is even";
  else
    return testing::AssertionFailure() << n << " is odd";
}

TEST(FibTest, BasicAssertion)
{
  EXPECT_EQ(Fib(3), 2);
  EXPECT_EQ(Fib(4), 3);
  EXPECT_EQ(Fib(5), 5);
  EXPECT_EQ(Fib(6), 8);
  ASSERT_EQ(Fib(5), 5);

  EXPECT_TRUE(IsEven(Fib(6)));
  EXPECT_FALSE(IsEven(Fib(5)));
}

// Type Assertions

template <typename T> class Foo {
 public:
  void Bar() { testing::StaticAssertTypeEq<int, T>(); }
};

/*
void Test2() { Foo<bool> foo; foo.Bar(); }
// causes compilation error
// static_assert(std::is_same<T1, T2>::value, "T1 and T2 are not the same type")
*/

// Skipping

TEST(SkipTest, DoesSkip) {
  GTEST_SKIP() << "Skipping single test";
  EXPECT_EQ(0, 1);  // Won't fail; it won't be executed
}

class SkipFixture : public ::testing::Test {
 protected:
  void SetUp() override {
    GTEST_SKIP() << "Skipping all tests for this fixture";
  }
};

// Tests for SkipFixture won't be executed.
TEST_F(SkipFixture, SkipsOneTest) {
  EXPECT_EQ(5, 7);  // Won't fail
  EXPECT_EQ(1, 2);
  EXPECT_EQ(3, 4);
}

TEST(MockTestStr, StrMatch) {
  ASSERT_THAT("awjebaneedleajbasbd", HasSubstr("needle"));
  EXPECT_THAT("d", MatchesRegex("\\w*\\d+"));
  EXPECT_THAT("wwwwwwwd", MatchesRegex("\\w*\\d+"));
}