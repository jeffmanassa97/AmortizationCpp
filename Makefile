CC = g++
CFLAGS = --std=c++11 -Wall -c
LFLAGS = --std=c++11
SRC = src
OBJ = obj
DOC = doc
TEST = test

all: amortize

amortize: $(OBJ)/main.o $(OBJ)/amortize.o
	$(CC) $(LFLAGS) $(OBJ)/main.o $(OBJ)/amortize.o -o amortize

$(OBJ)/main.o: $(SRC)/main.cpp $(SRC)/amortize.hpp
	$(CC) $(CFLAGS) $(SRC)/main.cpp -o $(OBJ)/main.o

$(OBJ)/amortize.o: $(SRC)/amortize.cpp $(SRC)/amortize.hpp
	$(CC) $(CFLAGS) $(SRC)/amortize.cpp -o $(OBJ)/amortize.o

.PHONY: clean doc test

doc:
	doxygen doxyfile

clean:
	rm -rf $(OBJ)/* amortize
