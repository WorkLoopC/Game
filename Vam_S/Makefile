CXX = g++
CXXFLAGS = -Wall -std=c++17

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
RES_DIR = resources

TARGET = $(BIN_DIR)/app
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC))

LIBS = -lsfml-graphics -lsfml-window -lsfml-system

all: $(TARGET) resources

$(TARGET): $(OBJ) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

resources: | $(BIN_DIR)
	cp -r $(RES_DIR)/* $(BIN_DIR)/

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(OBJ_DIR)/*.o $(TARGET)

.PHONY: all run clean resources