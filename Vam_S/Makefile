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

# Default target
all: $(TARGET) resources

# Build the final binary
$(TARGET): $(OBJ) | $(BIN_DIR)
	@echo "Linking $@ ..."
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

# Compile source files into objects
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@echo "Compiling $< ..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create directories if missing
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Copy resources
resources: | $(BIN_DIR)
	@echo "Copying resources ..."
	cp -r $(RES_DIR)/* $(BIN_DIR)/

# Run the program
run: all
	@echo "Running $(TARGET) ..."
	./$(TARGET)

# Clean everything
clean:
	@echo "Cleaning build ..."
	rm -rf $(OBJ_DIR) $(BIN_DIR)/app

.PHONY: all run clean resources