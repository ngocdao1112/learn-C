#makefile for building demo application
#edit this file to compile extra C files into their own programming
TARGETS = bad_memory

CROSS_TOOL = 
CC_CPP = $(CROSS_TOOL)g++
CC_C = $(CROSS_TOOL)gcc

CFLAGS = -Wall -Werror -g -std = c99

all: clean $(TARGETS)

$(TARGETS):
	$(CC_C) $(CFLAGS) $@.c - o $@

clean:
	del bad_memory

bad_memory: bad_memory.c
	gcc -Wall -Werror -g -std=c99 bad_memory.c -o bad_memory