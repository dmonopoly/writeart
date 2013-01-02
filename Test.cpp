/*
 * Test.cpp
 *	Just to test my WriteArt app.
 *  Created on: Dec 31, 2012
 *      Author: David Zhang
 */

#include "Standard.h"
#include "Converter.h"

using namespace std;

void begin();
void end();

int main() {
    begin();
    Converter conv;
    try {
    	conv.convert("testfile.txt");
    	cout << "Converted" << endl;

        // // testing
        // string t = "abcd456new6 word";
        // int j = conv.deleteAndGetNum(t, 4);
        // cout << t << endl;
        // cout << j << endl;

        // cout << "-----" << endl;

        // string s = "abcdefghijklmnop";
        // int i = 3;
        // conv.surround(s,2,i,20);
        // cout << s << endl;
        // cout << i << endl;

        // cout << "-----" << endl;
        // s = "lo2ve6";
        // conv.alter(s);
        // cout << s << endl;
        // s = "lo12ve6";
        // conv.alter(s);
        // cout << s << endl;

        // s = "lo12v16e18.";
        // conv.alter(s);
        // cout << s << endl;

    } catch (exception& e) {
    	cerr << "Error: " << e.what() << endl;
    }

    end();
    return 0;
}

// Begins initial output, including welcoming message
void begin() {
    enter(1);
//    cout << tab(1) << "David Zhang" << endl;
}

// Ends with final output
void end() {
    enter(1);
}
