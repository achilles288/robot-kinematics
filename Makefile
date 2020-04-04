ROOT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
DEBUG = 1


CC = gcc

ifeq ($(DEBUG), 1)
CFLAGS = -O0 -Wall -fPIC -c
else
CFLAGS = -O3 -Wall -fPIC -c -DNDEBUG
endif

AR = ar
RANLIB = ranlib


INCLUDES = \
	-Iinclude

LIBS = \
	-lm

SRCS = \
	src/chain2d_create.c \
	src/chain3d_create.c \
	src/fkine2d.c \
	src/fkine3d.c \
	src/link2d_join.c \
	src/link3d_join.c \
	src/math/mat3_multiply.c \
	src/math/mat3_transform.c \
	src/math/mat4_get_rotation.c \
	src/math/mat4_multiply.c \
	src/math/mat4_transform.c \
	src/math/mat_print.c \
	src/math/vec2_normalize.c \
	src/math/vec3_cross.c \
	src/math/vec3_dot.c \
	src/math/vec3_normalize.c
	
OBJS = $(patsubst src/%.c, build/%.o, $(SRCS))


all: robotkinematics


robotkinematics: mkdir $(OBJS)
ifeq ($(DEBUG), 1)
	@ $(CC) -shared -Wl,-soname,lib$@.so.1 -o lib/devel/lib$@.so.1.0 $(OBJS) $(LIBS)
	@ ln -sf $(ROOT_DIR)/lib/devel/lib$@.so.1.0 $(ROOT_DIR)/lib/devel/lib$@.so.1
	@ ln -sf $(ROOT_DIR)/lib/devel/lib$@.so.1.0 $(ROOT_DIR)/lib/devel/lib$@.so
	@ $(AR) -rc lib/devel/static/lib$@.a $(OBJS)
	@ $(RANLIB) lib/devel/static/lib$@.a
endif
	@ echo Compiled robot kinematics


$(OBJS): build/%.o: src/%.c
	@ $(CC) $(CFLAGS) $(INCLUDES) -o $@ $< $(LIBS)


docs: mkdir
	@ cd include; doxygen doxyfile
	-@ rm -r docs/api/*
	@ mv -f docs/html/* docs/api
	@ rm -r docs/html


mkdir:
	@ mkdir -p build
	@ mkdir -p build/math
	@ mkdir -p lib
	@ mkdir -p lib/devel
	@ mkdir -p lib/devel/static
	@ mkdir -p lib/static


clean:
	-@ rm -r build
	-@ rm -r lib

