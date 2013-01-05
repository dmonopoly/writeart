cmake_minimum_required(VERSION 2.8)

# Options
option(TEST "Build all tests." OFF) # makes boolean 'TEST' available

# Make PROJECT_SOURCE_DIR, PROJECT_BINARY_DIR, and PROJECT_NAME available
set(PROJECT_NAME MyProject)
project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "-g") # -Wall")

#set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include) if you want your own include/ directory
# then you can do include_directories(${COMMON_INCLUDES}) in other cmakelists.txt files

################################
# Normal Libraries & Executables
################################
add_library(standard_lib Standard.cpp Standard.h)
add_library(converter_lib Converter.cpp Converter.h)
add_executable(main Main.cpp)

target_link_libraries(main standard_lib converter_lib)

################################
# Testing
################################
if (TEST)
	# This adds another subdirectory, which has project(gtest)
	add_subdirectory(lib/gtest-1.6.0)

	enable_testing()

	# Include the gtest library
	# gtest_SOURCE_DIR is available due to project(gtest) above
	include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

	##############
	# Unit Tests
	##############
	# Naming
	set(UNIT_TESTS runUnitTests)

	add_executable(${UNIT_TESTS} ConverterTest.cpp)

	# standard linking to gtest stuff
	target_link_libraries(${UNIT_TESTS} gtest gtest_main)

	# extra linking for the project
	target_link_libraries(${UNIT_TESTS} standard_lib converter_lib)

	# This is so you can do 'make test' to see all your tests run, instead of manually running the executable runUnitTests to see those specific tests.
	add_test(NAME myUnitTests COMMAND runUnitTests)
endif()

