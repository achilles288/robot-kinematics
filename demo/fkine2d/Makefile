ROOT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))


CC = gcc

CFLAGS = -O0 -Wall


INCLUDES = \
	-I../../include

LIBS = \
	-lm \
	-L../../lib/devel \
	-lrobotkinematics \
	-Wl,-rpath=$(ROOT_DIR)/../../lib/devel


all:
	@ $(MAKE) -s -C ../..
	@ $(CC) $(CFLAGS) $(INCLUDES) -o main.o fkine2d.c $(LIBS)
	@ echo Compiled demo program

run:
	@ ./main.o
