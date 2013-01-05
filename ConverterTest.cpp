#include "gtest/gtest.h"

#include "Standard.h"
#include "Converter.h"

// The fixture for testing class Project1.
class ConverterTest : public ::testing::Test {
protected:
	Converter conv;
	ConverterTest() {
		// You can do set-up work for each test here.
	}

	virtual ~ConverterTest() {
		// You can do clean-up work that doesn't throw exceptions here.
	}

	// If the constructor and destructor are not enough for setting up
	// and cleaning up each test, you can define the following methods:
	virtual void SetUp() {
		// Code here will be called immediately after the constructor (right
		// before each test).
	}

	virtual void TearDown() {
		// Code here will be called immediately after each test (right
		// before the destructor).
	}
};

/* Class-specific tests */
// Tests single token change
TEST_F(ConverterTest, AlterTest) { // shows how to test a public method with a test fixture
	string s = "L25ife20";
	conv.alter(s);
	EXPECT_EQ("<span style=\"font-size:25px\">L</span><span style=\"font-size:20px\">ife</span>",s);
}

TEST_F(ConverterTest, IntExtraction) { // shows how to test a private method with a test fixture
	// Converter conv; don't need because this uses the fixture
	string t = "abcd123new6 word";
	int j = conv.deleteAndGetNum(t, 4);
	EXPECT_EQ("abcdnew6 word", t); // string should change
	EXPECT_EQ(123, j); // int should be correct
}

TEST(SpecificConverterTest, Surround) { // shows how to test a private method without a test fixture
	Converter conv; // need because no fixture used here
	string s = "abcdefgh";
	int i = 5;
	conv.surround(s,2,i,20);
    // s should have changed
	EXPECT_EQ("ab<span style=\"font-size:20px\">cde</span>fgh", s);
	
	// i should have moved to end of surrounded string to 'f'
    EXPECT_EQ(41, i); // index 41 is right at 'f'
}

// TEST_F(ConverterTest, DetectNewLine) {
// 	string s = "grow\nup";
// 	conv.alter(s);
	
// }

// auto included by gtest_main in CMakeLists.txt
// int main(int argc, char **argv) {
//   ::testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
// }