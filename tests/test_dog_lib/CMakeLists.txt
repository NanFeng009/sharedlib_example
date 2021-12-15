INCLUDE_DIRECTORIES(${ANIMAL_DIR}/inc
					${ANIMAL_DIR}/tests/cmockalib/cmocka/include
			       )

SET(CMAKE_C_FLAGS "-g")

SET(src_test_dog
	dog_test.c
	)

SET(lib_test_dog_LIBRARY
	dog
	cmockalib
	)


ADD_EXECUTABLE(dog_test ${src_test_dog})
TARGET_LINK_LIBRARIES(dog_test ${lib_test_dog_LIBRARY})
