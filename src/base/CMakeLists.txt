cmake_minimum_required( VERSION 2.8 )

set( CMAKE_CXX_FLAGS "-g -Wall -std=c++11" )

set( BASE_SOURCES atom.cpp molecule.cpp mixture.cpp )
add_library( base ${BASE_SOURCES} )

