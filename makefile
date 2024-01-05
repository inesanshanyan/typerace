CXX = g++ # Change this to your desired C++ compiler
CXXFLAGS = -std=c++11 -g -Wall -Wextra 

INCLUDE_DIR = ./includes
SRC_DIR = ./src
BUILD_DIR = ./build

# Get all source files
CONTROLLER_SRCS = $(wildcard $(SRC_DIR)/controller/*.cpp)
MODEL_SRCS = $(wildcard $(SRC_DIR)/model/*.cpp)
VIEW_SRCS = $(wildcard $(SRC_DIR)/view/*.cpp)
MAIN_SRC = main.cpp

CONTROLLER_OBJS = $(CONTROLLER_SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
MODEL_OBJS = $(MODEL_SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
VIEW_OBJS = $(VIEW_SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
MAIN_OBJ = $(BUILD_DIR)/main.o

TARGET = main

.PHONY: all clean directories

all: directories $(TARGET)

$(TARGET): $(CONTROLLER_OBJS) $(MODEL_OBJS) $(VIEW_OBJS) $(MAIN_OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@ -lncurses 

$(BUILD_DIR)/controller/%.o: $(SRC_DIR)/controller/%.cpp | directories
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(BUILD_DIR)/model/%.o: $(SRC_DIR)/model/%.cpp | directories
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(BUILD_DIR)/view/%.o: $(SRC_DIR)/view/%.cpp | directories
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(BUILD_DIR)/main.o: $(MAIN_SRC) | directories
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

directories:
	mkdir -p $(BUILD_DIR)/controller $(BUILD_DIR)/model $(BUILD_DIR)/view $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR) $(TARGET)
