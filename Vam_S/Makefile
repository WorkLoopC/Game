CXX = g++

CXXFLAGS = -Wall -std=c++20 -MMD -MP

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
RES_DIR = resources

TARGET = $(BIN_DIR)/app
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC))

DEPS = $(OBJ:.o=.d)

LIBS = -lsfml-graphics -lsfml-window -lsfml-system


all: $(TARGET) resources

$(TARGET): $(OBJ) | $(BIN_DIR)
	@echo "Linking $@ ..."
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@echo "Compiling $< ..."
	$(CXX) $(CXXFLAGS) -c $< -o $@


$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)


resources: | $(BIN_DIR)
	@echo "Syncing resources ..."
	cp -ru $(RES_DIR)/* $(BIN_DIR)/


run: all
	@echo "Running $(TARGET) ..."
	./$(TARGET)


clean:
	@echo "Cleaning build ..."
	rm -rf $(OBJ_DIR) $(BIN_DIR)/app

.PHONY: all run clean resources

-include $(DEPS)