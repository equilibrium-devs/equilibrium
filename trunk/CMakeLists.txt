CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(equilibrium)
ENABLE_LANGUAGE(CXX)

# What type of library we will be compiling.
IF(NOT CMAKE_BUILD_TYPE)
   SET(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build: Debug Release." FORCE)
ENDIF()

# Setting compiler flags for different build options. These can be compiler
# dependent.
IF(${CMAKE_CXX_COMPILER_ID} STREQUAL "Intel")
ELSEIF(${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
   SET(CMAKE_CXX_FLAGS "-std=c++0x")
   SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE_INIT}" CACHE STRING "" FORCE)
   SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG_INIT}" CACHE STRING "" FORCE)
ENDIF()

# Main directory where library, etc. will be installed.
IF(NOT CMAKE_INSTALL_PREFIX)
   SET(CMAKE_INSTALL_PREFIX $ENV{HOME}/equilibrium CACHE PATH "Path to installation directory." FORCE)
ENDIF()

# Sub-directories where executables, the library, headers, etc. will go.
SET(INSTALL_INCLUDE_DIR ${CMAKE_INSTALL_PREFIX}/include)
SET(INSTALL_LIB_DIR ${CMAKE_INSTALL_PREFIX}/lib)
SET(INSTALL_BIN_DIR ${CMAKE_INSTALL_PREFIX}/bin)
SET(INSTALL_TESTS_DIR ${CMAKE_INSTALL_PREFIX}/tests)

# Main directories.
ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(tests)

# Defining LIB_SRC_FILES to contain all files for the library.
SET(LIB_SRC_FILES ${BASE_SRC_FILES})

# Defining LIB_H_FILES to group all of the headers together.
SET(LIB_H_FILES ${BASE_H_FILES})

# Determining whether we want a shared library or static library.
OPTION(BUILD_SHARED "Build a shared library object." OFF)
IF(BUILD_SHARED)
   ADD_LIBRARY(equilibrium SHARED ${LIB_SRC_FILES})
ELSE()
   ADD_LIBRARY(equilibrium STATIC ${LIB_SRC_FILES})
ENDIF()

# Installing the library.
OPTION(INSTALL_LIBRARY "Install the C++ library." ON)
IF(INSTALL_LIBRARY)
   INSTALL(TARGETS equilibrium 
           LIBRARY DESTINATION ${INSTALL_LIB_DIR}
           ARCHIVE DESTINATION ${INSTALL_LIB_DIR})
   INSTALL(FILES ${LIB_H_FILES} DESTINATION ${INSTALL_INCLUDE_DIR})
ENDIF()

# Build any unit tests alongside the library.
OPTION(BUILD_TESTS "Build examples demonstrating library functionality." OFF)
IF(BUILD_TESTS)
   ADD_EXECUTABLE(AtomMoleculeTestCXX ${ATOM_MOLECULE_TEST_CXX})
   TARGET_LINK_LIBRARIES(AtomMoleculeTestCXX equilibrium)
   INSTALL(TARGETS AtomMoleculeTestCXX DESTINATION ${INSTALL_TESTS_DIR})
ENDIF()

