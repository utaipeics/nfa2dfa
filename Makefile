CXX=g++
SRC=$(wildcard src/*.cc)
BIN=main

all:
	$(CXX) -o $(BIN) $(SRC)

%.clean:
	rm $(BIN)

run:
	./$(BIN)
