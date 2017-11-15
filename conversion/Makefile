CC=gcc
CFLAGS=-c -Wall -Wextra

all: main

conv_io.o: conv_io.c
        $(CC) $(CFLAGS) conv_io.c

conversion.o: conversion.c
        $(CC) $(CFLAGS) conversion.c

main.o: main.c
        $(CC) $(CFLAGS) main.c

main: conv_io.o conversion.o main.o
        $(CC) conv_io.o conversion.o main.o -o main

clean:
        rm *o

mrproper:
        rm *o main
