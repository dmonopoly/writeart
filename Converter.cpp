/*
 * Converter.cpp
 *
 *  Created on: Dec 31, 2012
 *      Author: David Zhang
 */

#include "Converter.h"

Converter::Converter() {
}

Converter::~Converter() {
}

void Converter::convert(string filename) {
	vector<string> tokens;

	// Read in words into tokens
    ifstream fin;
    fin.open(filename.c_str());
    if (fin.fail())
    	cout << "No file present" << endl;
    else {
    	fin.peek(); // Important for peeking at the file so fin.eof works
		if (fin.eof()) { // ensure the file is not empty
			cout << "File empty." << endl;
		} else {
			string word; char c;
			int safe = 0;
			while (fin >> word) { // clean way to read; space separated
				tokens.push_back(word);
				cout << word << endl;
				while (fin.peek() == '\n') {
					tokens.push_back(NEW_LINE_STRING);
					c = fin.get();
				}
				
				safe++;
				if (safe == LIMIT) {
					cout << "Avoided infinite loop. Check format of input file.\n";
					break;
				}
			}
		}
	}

	// for (int i = 0; i < tokens.size(); i++) {
	// 	cout << tokens[i] << endl;
	// }

	// Alter tokens
	alterTokens(tokens);

	// Output
	string outputFile = filename.append(".html");
	ofstream fout(outputFile.c_str());
	for (int i = 0; i < tokens.size(); i++) {
		if (tokens[i] == NEW_LINE_STRING) {
			fout << tokens[i]; // no space after token if token is NEW_LINE_STRING is next
		} else {
			fout << tokens[i] << " ";
		}
	}

}

// Essential method that actually changes each token
void Converter::alterTokens(vector<string> &tokens) {
	for (int i = 0; i < tokens.size(); i++) {
		alter(tokens[i]);
	}
}

// pre: accepts a single token (word), like "L25ife20"
// post: removes numbers and surrounds with appropriate span tags
// sometimes gets the token NEW_LINE_STRING which we can immediately skip for speed
void Converter::alter(string &str) {
	if (str != NEW_LINE_STRING) {
		int a = 0;
		int i = 0;
		int size;
		while (i < str.size()) { // stri.size() shrinks a bit from deleteAndGetNum, i increases a lot in surround()
			if (isdigit(str.at(i))) { 
				size = deleteAndGetNum(str, i); // get combined digits as a number
				surround(str,a,i,size); // changes i
				a = i;
			} else {
				i++;
			}
		}
	}
}

// Deletes the number at index i of string s, and returns the number
// pre: i starts at isdigit char
int Converter::deleteAndGetNum(string &s, int i) {
	int num;
	stringstream ss;
	while (i < s.size()) { // size changes, i doesn't
		if (isdigit(s.at(i))) {
			ss << s.at(i);
			s.erase(i, 1); // erase 1 char starting at i
		} else {
			break;
		}
	}
	ss >> num;
	return num;
}

// Change string s to be surrounded with the proper span tags for characters from [a,b)
// adjusts b to be at the end of the surrounded result
void Converter::surround(string &s, int a, int &b, int size) {
	stringstream ss;
	ss << "<span style=\"font-size:" << size << "px\">" << s.substr(a,b-a) << "</span>";
	string result = ss.str();
	s.replace(a, b-a, result); // replace starting from a, length b-a, with the third param
	b = result.size() + a;
}

// would work    
// void Converter::test(string s) {
// 	cout << "okay" << endl;
// }