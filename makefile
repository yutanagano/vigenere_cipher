assert.o: unit_tests/assert/assert.c
	gcc -c unit_tests/assert/assert.c -o object_files/assert.o

caesar_transform_char.o: src/caesar_transform_char/caesar_transform_char.c
	gcc -c \
	src/caesar_transform_char/caesar_transform_char.c \
	-o object_files/caesar_transform_char.o

get_shift_at_position.o: src/get_shift_at_position/get_shift_at_position.c
	gcc -c \
	src/get_shift_at_position/get_shift_at_position.c \
	-o object_files/get_shift_at_position.o

process_key.o: src/process_key/process_key.c
	gcc -c \
	src/process_key/process_key.c \
	-o object_files/process_key.o

string_transform.o: src/string_transform/string_transform.c
	gcc -c \
	src/string_transform/string_transform.c \
	-o object_files/string_transform.o

test_caesar_transform_char.o:\
 unit_tests/test_caesar_transform_char/test_caesar_transform_char.c\
 unit_tests/assert/assert.h\
 src/caesar_transform_char/caesar_transform_char.h
	gcc -c \
	unit_tests/test_caesar_transform_char/test_caesar_transform_char.c \
	-o object_files/test_caesar_transform_char.o

test_get_shift_at_position.o:\
 unit_tests/test_get_shift_at_position/test_get_shift_at_position.c\
 unit_tests/assert/assert.h\
 src/get_shift_at_position/get_shift_at_position.h
	gcc -c \
	unit_tests/test_get_shift_at_position/test_get_shift_at_position.c \
	-o object_files/test_get_shift_at_position.o

test_process_key.o:\
 unit_tests/test_process_key/test_process_key.c\
 unit_tests/assert/assert.h\
 src/process_key/process_key.h
	gcc -c \
	unit_tests/test_process_key/test_process_key.c \
	-o object_files/test_process_key.o

test_string_transform.o:\
 unit_tests/test_string_transform/test_string_transform.c\
 unit_tests/assert/assert.h\
 src/string_transform/string_transform.h
	gcc -c \
	unit_tests/test_string_transform/test_string_transform.c \
	-o object_files/test_string_transform.o

test.o:\
 test/test.c\
 unit_tests/test_caesar_transform_char/test_caesar_transform_char.h\
 unit_tests/test_get_shift_at_position\
 unit_tests/test_process_key/test_process_key.h\
 unit_tests/test_string_transform/test_string_transform.h
	gcc -c test/test.c -o object_files/test.o

main.o:\
 main/main.c\
 src/process_key/process_key.h\
 src/string_transform/string_transform.h
	gcc -c main/main.c -o object_files/main.o

test:\
 test.o\
 assert.o\
 test_caesar_transform_char.o\
 caesar_transform_char.o\
 test_get_shift_at_position.o\
 get_shift_at_position.o\
 test_process_key.o\
 process_key.o\
 test_string_transform.o\
 string_transform.o
	gcc \
	object_files/test.o \
	object_files/assert.o \
	object_files/test_caesar_transform_char.o \
	object_files/caesar_transform_char.o \
	object_files/test_get_shift_at_position.o \
	object_files/get_shift_at_position.o \
	object_files/test_process_key.o \
	object_files/process_key.o \
	object_files/test_string_transform.o \
	object_files/string_transform.o \
	-o test/test_program \
	&& test/test_program

main:\
 main.o\
 process_key.o\
 string_transform.o\
 caesar_transform_char.o\
 get_shift_at_position.o
	gcc \
	object_files/main.o \
	object_files/process_key.o \
	object_files/string_transform.o \
	object_files/caesar_transform_char.o \
	object_files/get_shift_at_position.o \
	-o vcipher