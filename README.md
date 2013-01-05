# What is this?
*An experimental way to write so you can easily change font size.*  

Written in C++ with some testing help from Google Test (gtest).

# Try it out

## Quick
First **edit build/testfile.txt**. Then:

	cd build
	./main

Finally, check out testfile.txt.html and see it in a browser.

## More in depth
You can delete the build/ directory and recreate it from scratch.

Building the project from scratch:

	mkdir build
	cd build
	cmake ..
	make


If you want to run the tests too, do `cmake .. -DTEST=ON` and then `make`.  
`make test` would run all tests, and `./runUnitTests` would run the specific test file (there's only one).

