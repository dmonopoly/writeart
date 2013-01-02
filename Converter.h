/*
 * Converter.h
 *
 *  Created on: Dec 31, 2012
 *      Author: David Zhang
 */

#ifndef CONVERTER_H_
#define CONVERTER_H_

#include "Standard.h"

class Converter {
public:
	Converter();
    ~Converter();
    
    void convert(string filename);
    
    // would work
    // void test(string);
// private:
	void alterTokens(vector<string> &);
	void alter(string &s);
	int deleteAndGetNum(string &, int);
	void surround(string &, int a, int &b, int size);


	int getFontSize(string &);

};

#endif /* CONVERTER_H_ */
