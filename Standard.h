/*
 * Standard.h
 *  
 *  Created on: Nov 26, 2011
 */

#ifndef STANDARD_H_
#define STANDARD_H_

#include <iostream> // IO access
#include <stdio.h>
#include <iomanip>  // Format
#include <sstream>  // String helper
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std; // so cout, cin, and string work - here, and in the .cpp, AND ANY .H OR .CPP THAT INCLUDES THIS!
					// important: just have using namespace std; at the top or inherited in any FILE that you want to do string instead of std::string

// Allows easy tabbing, so you can use tab(1) and tab(2)
string tab(int n);

// Allows easy new lines, so you use enter(1) and enter(2)
void enter(int n);

// Returns true if s1 contains s2; false otherwise
bool contains(string s1, string s2);

// Returns true if long num1 contains long l2
bool contains(long num1, long num2);

// For asking yes or no questions
// Returns true if char is "y" or "Y"; false if "n" or "N"; otherwise, repeat question
bool askAndDecide(string question);

// Method that directly makes a string all lowercase
void toLowerCase(string &s);

// Useful printing method for 2 columns
template<typename A, typename B> void print2(const A& a, const B& b) {
	cout << fixed << setprecision(2);
	cout << tab(1) << left << setw(30) << a << right << b << endl;
}

// Useful printing method for 3 columns
template<typename A, typename B, typename C> void print3(const A& a, const B& b, const C& c) {
	cout << fixed << setprecision(2);
	cout << tab(1) << left << setw(30) << a << right << setw(20) << b << setw(20) << c << endl;
}

// Useful writing method for 3 columns, like above
template<typename A, typename B, typename C> void write3(ofstream &fout, const A& a, const B& b, const C& c) {
	fout << fixed << setprecision(2);
	fout << tab(1) << left << setw(30) << a << right << setw(20) << b << setw(20) << c << endl;
}

// Useful method to convert number to string
template <typename T>
string numberToString ( T Number )
{
	stringstream ss;
	ss << Number;
	return ss.str();
}

// Useful method to convert string to number; returns specified fail variable if unsuccessful
// Usage example: int i = stringToNumber<int>(response, -2), where response is a string
template <typename T> T stringToNumber (const string &Text, T fail) {
	stringstream ss(Text);
	T result;
	return ss >> result ? result : fail;
}

// Prompts for a number with the specified question
// Repeatedly asks until an acceptable answer is given
// Usage: askAndGetNumber<int>("What number?")
template <typename T> T askAndGetNumber(string question) {
    string response;
    cout << question;
    getline(cin, response);
    T i = stringToNumber<T>(response, -2);
    while (i == -2) {
        cout << tab(1) << "Improper response.\n";
        cout << question;
        getline(cin, response);
        i = stringToNumber<T>(response, -2);
    }
    return i;
}

#endif /* STANDARD_H_ */
