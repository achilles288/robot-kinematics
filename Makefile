ROOT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))


CC = gcc
CFLAGS = -O3 -Wall -fPIC -c

INCLUDES = 

LIBS = \
    -lm

SRCS = \
	src/rk_create_link.c \
	src/rk_forward_kinematics.c \
	src/rk_inverse_kinematics.c

OBJS = $(patsubst src/%.c, build/%.o, $(SRCS))


INCLUDES2 = \
	-Iinclude

LIBS2 = \
	-lglut \
	-lm \
	-Llib \
	-lrobotkinematics \
	-Wl,-rpath=$(ROOT_DIR)/lib


all: robotkinematics rktest


robotkinematics: mkdir $(OBJS)
	@ $(CC) -shared -Wl,-soname,lib$@.so.1 -o lib/lib$@.so.1.0 $(OBJS)
	@ ln -sf $(ROOT_DIR)/lib/lib$@.so.1.0 $(ROOT_DIR)/lib/lib$@.so.1
	@ ln -sf $(ROOT_DIR)/lib/lib$@.so.1.0 $(ROOT_DIR)/lib/lib$@.so
	@ echo [34mArchived library[0m

rktest: robotkinematics
	@ $(CC) -Wall $(INCLUDES2) -o test/aero.o test/src/aero.c $(LIBS2)
	@ echo [34mCompiled test program[0m

mkdir:
	@ mkdir -p build
	@ mkdir -p lib

$(OBJS): build/%.o: src/%.cpp
	@ $(CC) $(CFLAGS) $(INCLUDES) -o $@ $< $(LIBS)


run:
	@ $(ROOT_DIR)/test/simulation.o


clean:
	-@ rm -r $(ROOT_DIR)/build
	-@ rm -r $(ROOT_DIR)/lib
	-@ rm $(ROOT_DIR)/test/*.o

