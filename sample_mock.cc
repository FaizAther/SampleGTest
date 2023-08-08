#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "BaseClassInterface.hh"

struct MyMock : public BaseClassInterface {
  MOCK_METHOD(int, foo, ());
  MOCK_METHOD(int, bar, (int), (const));
};

struct DemoMock : public ::testing::Test {
  MyMock mock_obj;

  DemoMock() {
    EXPECT_CALL(mock_obj, foo())
      .WillOnce(testing::Return(5))
      .WillOnce(testing::Return(5));
    // EXPECT_CALL(mock_obj, bar(10))
    //   .WillOnce(testing::Return(10))
    //   .WillOnce(testing::Return(10));
  }
};

// this will fail becase we set expectation of 2 calls
// TEST_F(DemoMock, one_call) {
//   EXPECT_EQ(mock_obj.foo(), 5);
// }

TEST_F(DemoMock, two_call) {
  EXPECT_EQ(mock_obj.foo(), 5);
  EXPECT_EQ(mock_obj.foo(), 5);
}

struct DemoMockBar : public ::testing::Test {
  MyMock mock_obj;

  DemoMockBar() {
    EXPECT_CALL(mock_obj, bar(10))
      .WillRepeatedly(testing::Return(10));
  }
};

TEST_F(DemoMockBar, three_call_bar) {
  EXPECT_EQ(mock_obj.bar(10), 10);
  EXPECT_EQ(mock_obj.bar(10), 10);
  EXPECT_EQ(mock_obj.bar(10), 10);
}