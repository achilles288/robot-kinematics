CC_C = gcc
CC_CPP = g++

CFLAGS = -O0 -Wall


INCLUDES = \
	-I../include

LIBS = \
	-lgtest \
	-lgtest_main \
	-lm \
	-pthread


SRCS = \
	../src/chain2d_create.c \
	../src/chain3d_create.c \
	../src/fkine2d.c \
	../src/fkine3d.c \
	../src/link2d_join.c \
	../src/link3d_join.c \
	../src/math/mat3_multiply.c \
	../src/math/mat3_transform.c \
	../src/math/mat4_get_rotation.c \
	../src/math/mat4_multiply.c \
	../src/math/mat4_transform.c \
	../src/math/mat_print.c \
	../src/math/vec2_normalize.c \
	../src/math/vec3_cross.c \
	../src/math/vec3_dot.c \
	../src/math/vec3_normalize.c
	
OBJS1 = $(patsubst ../src/%.c, build/src/%.o, $(SRCS))


UNIT_TESTS = \
	unit/mat3_get_tests.cpp \
	unit/mat3_multiply_tests.cpp \
	unit/mat3_transform_tests.cpp \
	unit/mat4_get_tests.cpp \
	unit/mat4_multiply_tests.cpp \
	unit/mat4_transform_tests.cpp \
	unit/mat_print_tests.cpp \
	unit/vec2_tests.cpp \
	unit/vec3_tests.cpp

OBJS2 = $(patsubst unit/%.cpp, build/unit/%.o, $(UNIT_TESTS))


all: unit

unit: mkdir $(OBJS1) $(OBJS2)
	@ $(CC_CPP) $(CFLAGS) $(INCLUDES) -o build/tests.o $(OBJS1) $(OBJS2) $(LIBS)
	@ ./build/tests.o

$(OBJS1): build/src/%.o: ../src/%.c
	@ $(CC_C) $(CFLAGS) -c $(INCLUDES) -o $@ $<

$(OBJS2): build/unit/%.o: unit/%.cpp
	@ $(CC_CPP) $(CFLAGS) -c $(INCLUDES) -o $@ $<


mkdir:
	@ mkdir -p build
	@ mkdir -p build/src
	@ mkdir -p build/src/math
	@ mkdir -p build/unit

clean:
	-@ rm -r build


TEST = tests

run:
	@ ./build/$(TEST).o
