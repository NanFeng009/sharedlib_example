# Make sure the compiler can find include files from our Hello library.
include_directories ("${ANIMAL_DIR}/src/dog_lib")
include_directories ("${ANIMAL_DIR}/src/cat_lib")

# Make sure the linker can find the library once it is built.
link_directories (${PROJECT_BINARY_DIR}/lib)

# Add executable called "ani" that is built from the source files
# "main.c".  The extensions are automatically found.
add_executable (ani main.c)

# Link the executable to the Hello library.
target_link_libraries (ani dog)
target_link_libraries (ani cat)


ADD_SUBDIRECTORY(dog_lib)
ADD_SUBDIRECTORY(cat_lib)
