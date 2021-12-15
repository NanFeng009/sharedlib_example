cmake_minimum_required(VERSION 2.6)

# The name of our project is "HELLO".  CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
project ("ani" C)

SET(ANIMAL_DIR ${PROJECT_SOURCE_DIR})

SET(BUILD_SHARED_LIBS "Build using shared libraries" ON)

SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# Recurse into the "Hello" and "Demo" subdirectories.  This does not actually
# cause another cmake executable to run.  The same process will walk through
# the project's entire directory structure.
ADD_SUBDIRECTORY (src)
ADD_SUBDIRECTORY (tests/cmockalib)
ADD_SUBDIRECTORY (tests/test_dog_lib)

enable_testing()

# does the ani run
add_test(NAME Runs COMMAND ani)
