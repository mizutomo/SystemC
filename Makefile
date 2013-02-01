CC = g++
CFLAGS = -Wall -g
EXTRA_LIB = -O2

MODULE = run

SRCS = rgb2yuv.cpp tb.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

include ../Makefile.defs
