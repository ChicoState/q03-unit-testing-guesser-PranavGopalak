/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

/* Example test
TEST(GuesserTest, smoke_test)
{
    ASSERT_EQ( 1+1, 2 );
}
*/

TEST(GuesserTest, exact_match_test) {
    Guesser guesser("apple");
    ASSERT_TRUE(guesser.match("apple"));
}

TEST(GuesserTest, non_match_test) {
    Guesser guesser("apple");
    ASSERT_FALSE(guesser.match("banana"));
}

TEST(GuesserTest, partial_match_test) {
    Guesser guesser("apple");
    ASSERT_FALSE(guesser.match("applx"));
}

TEST(GuesserTest, case_sensitivity_test) {
    Guesser guesser("Apple");
    ASSERT_FALSE(guesser.match("apple"));
}

TEST(GuesserTest, true_case_sensitivity_test) {
    Guesser guesser("ApplE");
    ASSERT_TRUE(guesser.match("ApplE"));
}

TEST(GuesserTest, empty_string_test) {
    Guesser guesser("apple");
    ASSERT_FALSE(guesser.match(""));
}

TEST(GuesserTest, empty_secret_test) {
    Guesser guesser("");
    ASSERT_TRUE(guesser.match(""));
}

TEST(GuesserTest, unexpected_empty_test) {
    Guesser guesser("");
    ASSERT_FALSE(guesser.match("banana"));
}