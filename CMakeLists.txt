cmake_minimum_required( VERSION 2.8 )

project( equilibrium )

set( CMAKE_CXX_FLAGS "-g -Wall" )

set( SOURCES main.cpp )
set( LIBRARIES base )

include_directories( src )
include_directories( src/base )

add_subdirectory( src )

add_executable( equilibrium "${SOURCES}" )
target_link_libraries( equilibrium "${LIBRARIES}" )

