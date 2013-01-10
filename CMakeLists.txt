cmake_minimum_required(VERSION 2.8)

# Options
option(TEST "Build all tests." OFF) # makes boolean 'TEST' available. turn on with cmake .. -DTEST=ON

# Make PROJECT_SOURCE_DIR, PROJECT_BINARY_DIR, and PROJECT_NAME available
set(PROJECT_NAME MyProject)
project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "-g") # -Wall")

#set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include) if you want your own include/ directory
# then you can do include_directories(${COMMON_INCLUDES}) in other cmakelists.txt files

################################
# Normal Libraries & Executables
################################
include_directories(src)
include_directories(lib/mylib) # tell cmake to look in lib/mylib for source files, since we use lib/mylib/Standard.cpp

# Create libraries
add_library(standard_lib lib/mylib/Standard.cpp lib/mylib/Standard.h)
add_library(converter_lib src/Converter.cpp src/Converter.h)

# Create executables
add_executable(main src/Main.cpp)

# Link executables to libraries
target_link_libraries(main standard_lib converter_lib)

################################
# Testing
################################
if (TEST)
	include_directories(test) # open the door to looking for source files in test/

	##############
	# gtest prep
	##############
	# This adds another subdirectory, which has project(gtest)
	add_subdirectory(lib/gtest-1.6.0) # open the door to using the CMakeLists.txt in this folder
	enable_testing()
	# Include the gtest library
	# gtest_SOURCE_DIR is available due to project(gtest) above
	include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

	##############
	# Unit Tests
	##############
	# Naming of test file
	set(UNIT_TESTS runUnitTests)

	add_executable(${UNIT_TESTS} test/ConverterTest.cpp)

	# standard linking to gtest stuff
	target_link_libraries(${UNIT_TESTS} gtest gtest_main)

	# extra linking for the project
	target_link_libraries(${UNIT_TESTS} standard_lib converter_lib)

	# This is so you can do 'make test' to see all your tests run, instead of manually running the executable runUnitTests to see those specific tests.
	add_test(NAME myUnitTests COMMAND runUnitTests)
endif()

