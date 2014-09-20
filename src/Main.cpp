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

// In progress - for command line stuff
// int main(int argc, char* argv[]) { // or char** argv
//     try {
//         if (argc == 1) {
//             string filename = argv[1]; // argv[0] is the command used to execute the c++, like "./a.out"
//             Converter conv;
//             try {
//                 conv.ConvertFromFile(filename);
//                 cout << "Converted" << endl;
//             } catch (exception &e) {
//              cerr << "Error: " << e.what() << endl;
//             }
//         } else {
//             cerr << "Please pass the filename as an argument." << endl;
//         }
//         return 0;
//     } catch (exception &e) {
//         cerr << e.what() << endl;
//     }
// }

// Working for testfile.txt
int main() {// (int argc, char* argv[]) // or char** argv
    begin();
    Converter conv;
    try {
    	conv.ConvertFromFile("testfile.txt");
    	cout << "Converted" << endl;
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
