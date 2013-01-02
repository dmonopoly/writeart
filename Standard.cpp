/*
 * Standard.cpp
 *
 *  Created on: Nov 26, 2011
 */

#include "Standard.h"

string tab(int n) {
    string tab = "";
    for (int i=0; i<n; i++) {
        tab += "\t";
    }
    return tab;
}

void enter(int n) {
    for (int i=0; i < n; i++) {
        cout << endl;
    }
}

bool contains(string s1, string s2) {
    if (std::string::npos != s1.find(s2))
        return true;
    else
        return false;
}

bool contains(long num1, long num2) {
	stringstream ss;
	ss << num1;
	string s1 = ss.str();
	ss.str("");
	ss << num2;
	string s2 = ss.str();
	return contains(s1, s2);
}

bool askAndDecide(string question) {
    char response;
    cout << question;
    cin >> response;
    while (response != 'n' && response != 'N' && response != 'y' && response != 'Y') {
        cout << "Improper response.\n";
        cout << question;
        cin >> response;
    }

    switch(response) {
        case 'n':
        case 'N': return false;
        case 'y':
        case 'Y': return true;
    }
}

void toLowerCase(string &s) {
    for (int i=0; i < s.size(); i++) {
        s[i] = tolower(s[i]);
    }
}
