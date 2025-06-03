CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall

SRC = dynamic_programming.cpp
ALG = algorithm/sequence_difference.cpp
OUT = bin/dynamic_programming

all: $(OUT)

$(OUT): $(SRC) $(ALG) | bin
	$(CXX) $(CXXFLAGS) $(SRC) $(ALG) -o $(OUT)

bin:
	mkdir -p bin

run: $(OUT)
	./$(OUT)

clean:
	rm -rf bin

.PHONY: all run clean
