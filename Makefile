# Variables
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20 $(shell find Headers/inc -type d | sed 's/^/-I/') `sdl2-config --cflags` `pkg-config --cflags SDL2_image` `pkg-config --libs SDL2_ttf`
LDFLAGS = `sdl2-config --libs` `pkg-config --libs SDL2_image` `pkg-config --libs SDL2_ttf` -lm
SRC = main.cpp $(shell find Sources/src -name '*.cpp') # Trouve tous les fichiers .cpp de manière récursive
OBJ = $(SRC:.cpp=.o) # Convertit les fichiers .cpp en fichiers .o
TARGET = exe

# Règles
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

# Pour éviter les conflits avec des fichiers nommés "clean"
.PHONY: clean all
