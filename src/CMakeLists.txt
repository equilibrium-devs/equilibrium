cmake_minimum_required( VERSION 2.8 )

set( CMAKE_CXX_FLAGS "-g -Wall -std=c++11" )

add_subdirectory( base )

set( SOURCES main.cpp )
set( LIBRARIES base )

include_directories( base )

add_executable( equilibrium "${SOURCES}" )
target_link_libraries( equilibrium "${LIBRARIES}" )

