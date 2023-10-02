CC = gcc
CXXFLAGS = -O2 -std=c++14
LDFLAGS = -lstdc++
OUT = file



all: file

file: fruits.o
	$(CC) fruits.o -o $(OUT) $(LDFLAGS)

fruits: fruits.cpp
	$(CC) -c fruits.cpp $(CXXFLAGS)