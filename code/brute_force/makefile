CXX = g++
CXXFLAGS = -std=c++17 -O0 -Wall

SRC = brute_force.cpp
ALG = algorithm/sequence_difference.cpp
OUT = bin/brute_force

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
