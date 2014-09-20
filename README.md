# What is this?
*An experimental way to write so you can easily change font size.*  

Written in C++ with some testing help from Google Test (gtest).

# Try it out

Build the project:

	mkdir build
	cd build
	cmake ..
	make

If you want to run the tests too, make sure to have done this (to turn the boolean for testing on), also in build/: 

	cmake .. -DTEST=ON
	make

The command `make test` would run all tests, and `./runUnitTests` would run the specific test file (there's only one).

Now, to run stuff (still in build/):

First **create testfile.txt** (in build/) and give it something like below:

	I believe22 the world can be a better26 place.26
	The world can be different.30

Finally:

	./main

And open the generated testfile.txt.html in the browser.
