ROOT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
SHARED = 1


CC = gcc
CFLAGS = -O3 -Wall -fPIC -c

AR = ar
RANLIB = ranlib


INCLUDES = \
	-Iinclude

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
	src/math/vec2_normalize.c \
	src/math/vec3_cross.c \
	src/math/vec3_dot.c \
	src/math/vec3_normalize.c
	
OBJS = $(patsubst src/%.c, build/%.o, $(SRCS))


all: robotkinematics


robotkinematics: mkdir $(OBJS)
ifeq ($(SHARED), 1)
	@ $(CC) -shared -Wl,-soname,lib$@.so.1 -o lib/shared/lib$@.so.1.0 $(OBJS)
	@ ln -sf $(ROOT_DIR)/lib/shared/lib$@.so.1.0 $(ROOT_DIR)/lib/shared/lib$@.so.1
	@ ln -sf $(ROOT_DIR)/lib/shared/lib$@.so.1.0 $(ROOT_DIR)/lib/shared/lib$@.so
	@ echo Compiled robot kinematics
else
	@ $(AR) -rc lib/lib$@.a $(OBJS)
	@ $(RANLIB) lib/lib$@.a
	@ echo Archived robot kinematics
endif


$(OBJS): build/%.o: src/%.c
	@ $(CC) $(CFLAGS) $(INCLUDES) -o $@ $< $(LIBS)


doc: mkdir
	@ cd include; doxygen doxyfile


mkdir:
	@ mkdir -p build
	@ mkdir -p build/math
	@ mkdir -p lib
	@ mkdir -p lib/shared


clean:
	-@ rm -r build
	-@ rm -r lib

