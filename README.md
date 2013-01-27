# What is this?
*An experimental way to write so you can easily change font size.*  

Written in C++ with some testing help from Google Test (gtest).

# Try it out

## Quick (for Mac OS only)
First **edit build/testfile.txt**. Then:

	cd build
	./main

Finally, check out testfile.txt.html and see it in a browser.

## More in depth
You can delete the build/ directory and recreate it from scratch.

Building the project from scratch (Mac only):

	mkdir build
	cd build
	cmake ..
	make


If you want to run the tests too, make sure to have done this (to turn the boolean for testing on), also in build/: 

	cmake .. -DTEST=ON
	make

The command `make test` would run all tests, and `./runUnitTests` would run the specific test file (there's only one).

