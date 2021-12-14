SET(CMOCKA_FLAGS "-std=gnu99 -Wpedantic -Wall -Wshadow -Wmissing-prototypes -Wcast-align -Werror=address -Wstrict-prototypes -Werror=strict-prototypes -Wwrite-strings -Werror=write-strings -Werror-implicit-function-declaration -Wpointer-arith -Werror=pointer-arith -Wdeclaration-after-statement -Werror=declaration-after-statement -Wreturn-type -Werror=return-type -Wuninitialized -Werror=uninitialized -Werror=strict-overflow -Wstrict-overflow=2 -Wno-format-zero-length -Wmissing-field-initializers -Wformat-security -Werror=format-security -fno-common -Wformat -fno-common -fstack-protector-strong")

SET(CMAKE_C_FLAGS "${CMOCKA_FLAGS} -DHAVE_SIGNAL_H")


INCLUDE_DIRECTORIES(${ANIMAL_DIR}/tests/cmockalib
				    ${ANIMAL_DIR}/tests/cmockalib/cmocka/include
					${ANIMAL_DIR}/tests/cmockalib/cmocka/include/cmockery
					)


SET(src_cmockalib
	cmocka/src/cmocka.c
	)

ADD_LIBRARY(cmockalib STATIC ${src_cmockalib})

