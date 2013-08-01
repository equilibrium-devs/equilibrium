cmake_minimum_required( VERSION 2.8 )

set( SOURCES main.cpp )
set( LIBRARIES base )

include_directories( base )
add_subdirectory( base )

add_executable( equilibrium "${SOURCES}" )
target_link_libraries( equilibrium "${LIBRARIES}" )

