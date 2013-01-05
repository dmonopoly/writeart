/*
 * Converter.h
 *
 *  Created on: Dec 31, 2012
 *      Author: David Zhang
 */

#ifndef CONVERTER_H_
#define CONVERTER_H_

#include "gtest/gtest_prod.h" // to allow testing private members
#include "Standard.h"

#define NEW_LINE_STRING "<br>\n"
#define LIMIT 100000 // limit to number of words; allows check for infinite while loop

class Converter {
	friend class ConverterTest; // needed only for FRIEND_TESTs that use TEST_F (with test fixture)
			// can be public, private, whatever

public:
	Converter();
    virtual ~Converter();
    
    void convert(const string filename);

	void alter(string &s);

private:
	void alterTokens(vector<string> &);
	// void alter(string &s); // should be private, but for demonstration, leaving it public
	int deleteAndGetNum(string &, int);
	void surround(string &, int a, int &b, int size);

	// To test private methods - must have FRIEND_TEST
	FRIEND_TEST(ConverterTest, IntExtraction); // to test private method with test fixture
  	FRIEND_TEST(SpecificConverterTest, Surround); // to test private method without test fixture

  	FRIEND_TEST(ConverterTest, DetectNewLine);
};

#endif /* CONVERTER_H_ */
