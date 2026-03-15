CXX = g++
CXXFLAGS = -Wall -std=c++17

TARGET = app

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

LIBS = -lsfml-graphics -lsfml-window -lsfml-system

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ) $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f *.o $(TARGET)