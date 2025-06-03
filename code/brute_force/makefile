# Makefile para la versión de fuerza bruta

CXX = g++
CXXFLAGS = -std=c++17 -O0 -Wall

SRC_DIR = algorithm
BIN_DIR = bin
BUILD_TARGET = $(BIN_DIR)/brute_force

$(BUILD_TARGET): $(SRC_DIR)/sequence_difference.cpp | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

run: $(BUILD_TARGET)
	./$(BUILD_TARGET) < input.txt > output.txt

clean:
	rm -rf $(BIN_DIR)

.PHONY: run clean
