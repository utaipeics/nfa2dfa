CXX=g++
SRC=$(wildcard regexcpp/*.cc)
BIN=main

all:
	$(CXX) -o $(BIN) $(SRC)

%.clean:
	rm $(BIN)

run:
	./$(BIN)
