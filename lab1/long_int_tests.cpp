#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "long_int.h"

using namespace std;

TEST(long_int_constructor, long_int_constructor1) { 
  long_int a("123");
  vector<int> number = {1,2,3};
  EXPECT_EQ(a.get_sign(), '+');
  EXPECT_EQ(a.get_number(), number);
}

TEST(long_int_constructor, long_int_constructor2) {
  long_int a("-123");
  vector<int> number = {1,2,3};
  EXPECT_EQ(a.get_sign(), '-');
  EXPECT_EQ(a.get_number(), number);
}

TEST(long_int_constructor, long_int_constructor3) {
  long_int a("+123");
  vector<int> number = {1,2,3};
  EXPECT_EQ(a.get_sign(), '+');
  EXPECT_EQ(a.get_number(), number);
}

TEST(long_int_constructor, long_int_constructor4) {
  long_int a("");
  vector<int> number = {};
  EXPECT_EQ(a.get_sign(), '+');
  EXPECT_EQ(a.get_number(), number);
}

TEST(long_int_print, long_int_print1) {
  long_int a("123");
  stringstream new_cout;
  streambuf* old_cout = cout.rdbuf(new_cout.rdbuf());
  cout << a;
  cout.rdbuf(old_cout); 
  EXPECT_EQ(new_cout.str(), "123");
}

TEST(long_int_print, long_int_print2) {
  long_int a("-123");
  stringstream new_cout;
  streambuf* old_cout = cout.rdbuf(new_cout.rdbuf());
  cout << a;
  cout.rdbuf(old_cout); 
  EXPECT_EQ(new_cout.str(), "-123");
}

TEST(long_int_sum, long_int_sum1) {
  long_int a("923"), b("224");
  vector<int> number = {1,1,4,7};
  EXPECT_EQ((a+b).get_sign(), '+');
  EXPECT_EQ((a+b).get_number(), number);
}

TEST(long_int_sum, long_int_sum2) {
  long_int a("1230"), b("12");
  a += b;
  vector<int> number = {1,2,4,2};
  EXPECT_EQ(a.get_sign(), '+');
  EXPECT_EQ(a.get_number(), number);
}

TEST(long_int_sum, long_int_sum3) {
  long_int a("-123"), b("123");
  vector<int> number = {0};
  EXPECT_EQ((a+b).get_sign(), '+');
  EXPECT_EQ((a+b).get_number(), number);
}

TEST(long_int_sum, long_int_sum4) {
  long_int a("1034"), b("-71");
  a += b;
  vector<int> number = {9,6,3};
  EXPECT_EQ(a.get_sign(), '+');
  EXPECT_EQ(a.get_number(), number);
}

TEST(long_int_and_int_sum, long_int_and_int_sum1) {
  long_int a("-7");
  int b = -123;
  vector<int> number = {1,3,0};
  EXPECT_EQ((a+b).get_sign(), '-');
  EXPECT_EQ((a+b).get_number(), number);
}

TEST(long_int_and_int_sum, long_int_and_int_sum2) {
  long_int a("45");
  int b = -1069;
  a += b;
  vector<int> number = {1,0,2,4};
  EXPECT_EQ(a.get_sign(), '-');
  EXPECT_EQ(a.get_number(), number);
}

TEST(long_int_diff, long_int_diff1) {
  long_int a("123"), b("123");
  vector<int> number = {0};
  EXPECT_EQ((a-b).get_sign(), '+');
  EXPECT_EQ((a-b).get_number(), number);
}

TEST(long_int_diff, long_int_diff2) {
  long_int a("123"), b("122");
  a -= b;
  vector<int> number = {1};
  EXPECT_EQ(a.get_sign(), '+');
  EXPECT_EQ(a.get_number(), number);
}

TEST(long_int_diff, long_int_diff3) {
  long_int a("120"), b("123");
  vector<int> number = {3};
  EXPECT_EQ((a-b).get_sign(), '-');
  EXPECT_EQ((a-b).get_number(), number);
}

TEST(long_int_and_int_diff, long_int_and_int_diff1) {
  long_int a("123");
  int b = -12;
  a -= b;
  vector<int> number = {1,3,5};
  EXPECT_EQ(a.get_sign(), '+');
  EXPECT_EQ(a.get_number(), number);
}

TEST(long_int_and_int_diff, long_int_and_int_diff2) {
  long_int a("-123");
  int b = 1000;
  vector<int> number = {1,1,2,3};
  EXPECT_EQ((a-b).get_sign(), '-');
  EXPECT_EQ((a-b).get_number(), number);
}

TEST(long_int_and_int_diff, long_int_and_int_diff3) {
  long_int a("-123");
  int b = -1;
  a -= b;
  vector<int> number = {1,2,2};
  EXPECT_EQ(a.get_sign(), '-');
  EXPECT_EQ(a.get_number(), number);
}

TEST(long_int_multipl, long_int_multipl1) {
  long_int a("123"), b("0");
  vector<int> number = {0};
  EXPECT_EQ((a*b).get_sign(), '+');
  EXPECT_EQ((a*b).get_number(), number);
}

TEST(long_int_multipl, long_int_multipl2) {
  long_int a("0"), b("-123");
  a *= b;
  vector<int> number = {0};
  EXPECT_EQ(a.get_sign(), '+');
  EXPECT_EQ(a.get_number(), number);
}

TEST(long_int_multipl, long_int_multipl3) {
  long_int a("123"), b("9");
  vector <int> number = {1,1,0,7};
  EXPECT_EQ((a*b).get_sign(), '+');
  EXPECT_EQ((a*b).get_number(), number);
}

TEST(long_int_and_int_multipl, long_int_and_int_multipl1) {
  long_int a("12");
  int b = -10;
  a *= b;
  vector<int> number = {1,2,0};
  EXPECT_EQ(a.get_sign(), '-');
  EXPECT_EQ(a.get_number(), number);
}

TEST(long_int_and_int_multipl, long_int_and_int_multipl2) {
  long_int a("-123");
  int b = 1234;
  vector<int> number = {1,5,1,7,8,2};
  EXPECT_EQ((a*b).get_sign(), '-');
  EXPECT_EQ((a*b).get_number(), number);
}

TEST(long_int_and_int_multipl, long_int_and_int_multipl3) {
  long_int a("-1");
  int b = -5;
  a *= b;
  vector<int> number = {5};
  EXPECT_EQ(a.get_sign(), '+');
  EXPECT_EQ(a.get_number(), number);
}

TEST(long_int_div, long_int_div1) {
  long_int a("1"), b("0");
  vector<int> number = {};
  EXPECT_EQ((a/b).get_sign(), '+');
  EXPECT_EQ((a/b).get_number(), number);
}

TEST(long_int_div, long_int_div2) {
  long_int a("-123"), b("123");
  a /= b;
  vector<int> number = {1};
  EXPECT_EQ(a.get_sign(), '-');
  EXPECT_EQ(a.get_number(), number);
}

TEST(long_int_div, long_int_div3) {
  long_int a("-123"), b("124");
  vector<int> number = {0};
  EXPECT_EQ((a/b).get_sign(), '+');
  EXPECT_EQ((a/b).get_number(), number);
}

TEST(long_int_and_int_div, long_int_and_int_div1) {
  long_int a("123");
  int b = -2;
  a /= b;
  vector<int> number = {6,1};
  EXPECT_EQ(a.get_sign(), '-');
  EXPECT_EQ(a.get_number(), number);
}

TEST(long_int_and_int_div, long_int_and_int_div2) {
  long_int a("1234");
  int b = 123;
  vector<int> number = {1,0};
  EXPECT_EQ((a/b).get_sign(), '+');
  EXPECT_EQ((a/b).get_number(), number);
}

TEST(long_int_and_int_div, long_int_and_int_div3) {
  long_int a("-12");
  int b = -4;
  a /= b;
  vector<int> number = {3};
  EXPECT_EQ(a.get_sign(), '+');
  EXPECT_EQ(a.get_number(), number);
}

TEST(long_int_pre_increment, long_int_pre_increment) {
  long_int a("-2");
  vector<int> number = {0};
  EXPECT_EQ((++a).get_sign(), '-');
  EXPECT_EQ((++a).get_number(), number);
}

TEST(long_int_post_increment, long_int_post_increment) {
  long_int a("-2");
  vector<int> number = {1};
  EXPECT_EQ((a++).get_sign(), '-');
  EXPECT_EQ((a++).get_number(), number);
}

TEST(long_int_pre_decrement, long_int_pre_decrement) {
  long_int a("1002");
  vector<int> number = {1,0,0,0};
  EXPECT_EQ((--a).get_sign(), '+');
  EXPECT_EQ((--a).get_number(), number);
}

TEST(long_int_post_decrement, long_int_post_decrement) {
  long_int a("1002");
  vector<int> number = {1,0,0,1};
  EXPECT_EQ((a--).get_sign(), '+');
  EXPECT_EQ((a--).get_number(), number);
}

TEST(long_int_to_int, long_int_to_int1) {
  long_int a("2147483647");
  int int_a = (int)a;
  EXPECT_EQ(int_a, 2147483647);
}

TEST(long_int_to_int, long_int_to_int2) {
  long_int a("-2147483648");
  int int_a = (int)a;
  EXPECT_EQ(int_a, -2147483648);
}

TEST(long_int_to_int, long_int_to_int3) {
  long_int a("0");
  int int_a = (int)a;
  EXPECT_EQ(int_a, 0);
}

TEST(long_int_to_int, long_int_to_int4) {
  long_int a("2147483650");
  int int_a = (int)a;
  EXPECT_EQ(int_a, 3);
}

TEST(long_int_to_int, long_int_to_int5) {
  long_int a("-2147483650");
  int int_a = (int)a;
  EXPECT_EQ(int_a, -3);
}

TEST(long_int_comparing, long_int_comparing1) {
  long_int a("123"), b("122");
  EXPECT_EQ(a > b, 1);
}

TEST(long_int_comparing, long_int_comparing2) {
  long_int a("123"), b("124");
  EXPECT_EQ(a > b, 0);
}

TEST(long_int_comparing, long_int_comparing3) {
  long_int a("123"), b("123");
  EXPECT_EQ(a >= b, 1);
}

TEST(long_int_comparing, long_int_comparing4) {
  long_int a("1"), b("123");
  EXPECT_EQ(a >= b, 0);
}

TEST(long_int_comparing, long_int_comparing5) {
  long_int a("0"), b("1");
  EXPECT_EQ(a < b, 1);
}

TEST(long_int_comparing, long_int_comparing6) {
  long_int a("123"), b("-124");
  EXPECT_EQ(a < b, 0);
}

TEST(long_int_comparing, long_int_comparing7) {
  long_int a("0"), b("0");
  EXPECT_EQ(a <= b, 1);
}

TEST(long_int_comparing, long_int_comparing8) {
  long_int a("100001"), b("100000");
  EXPECT_EQ(a <= b, 0);
}

TEST(long_int_comparing, long_int_comparing9) {
  long_int a("-123"), b("-123");
  EXPECT_EQ(a == b, 1);
}

TEST(long_int_comparing, long_int_comparing10) {
  long_int a("123"), b("-123");
  EXPECT_EQ(a == b, 0);
}

TEST(long_int_comparing, long_int_comparing11) {
  long_int a("1"), b("-1");
  EXPECT_EQ(a != b, 1);
}

TEST(long_int_comparing, long_int_comparing12) {
  long_int a("1"), b("1");
  EXPECT_EQ(a != b, 0);
}

TEST(long_int_and_int_comparing, long_int_and_int_comparing1) {
  long_int a("-123");
  int b = -124;
  EXPECT_EQ(a > b, 1);
}

TEST(long_int_and_int_comparing, long_int_and_int_comparing2) {
  long_int a("-123");
  int b = -122;
  EXPECT_EQ(a > b, 0);
}

TEST(long_int_and_int_comparing, long_int_and_int_comparing3) {
  long_int a("123");
  int b = 123;
  EXPECT_EQ(a >= b, 1);
}

TEST(long_int_and_int_comparing, long_int_and_int_comparing4) {
  long_int a("1");
  int b = 2;
  EXPECT_EQ(a >= b, 0);
}

TEST(long_int_and_int_comparing, long_int_and_int_comparing5) {
  long_int a("-123");
  int b = 123;
  EXPECT_EQ(a < b, 1);
}

TEST(long_int_and_int_comparing, long_int_and_int_comparing6) {
  long_int a("1");
  int b = 0;
  EXPECT_EQ(a < b, 0);
}

TEST(long_int_and_int_comparing, long_int_and_int_comparing7) {
  long_int a("-1");
  int b = 0;
  EXPECT_EQ(a <= b, 1);
}

TEST(long_int_and_int_comparing, long_int_and_int_comparing8) {
  long_int a("11");
  int b = 1;
  EXPECT_EQ(a <= b, 0);
}

TEST(long_int_and_int_comparing, long_int_and_int_comparing9) {
  long_int a("123");
  int b = 123;
  EXPECT_EQ(a == b, 1);
}

TEST(long_int_and_int_comparing, long_int_and_int_comparing10) {
  long_int a("123");
  int b = -123;
  EXPECT_EQ(a == b, 0);
}

TEST(long_int_and_int_comparing, long_int_and_int_comparing11) {
  long_int a("0");
  int b = 1;
  EXPECT_EQ(a != b, 1);
}

TEST(long_int_and_int_comparing, long_int_and_int_comparing12) {
  long_int a("-123");
  int b = -123;
  EXPECT_EQ(a != b, 0);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::InitGoogleMock(&argc, argv);
  
  return RUN_ALL_TESTS();
}   