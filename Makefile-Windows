# Variables
CXX = g++
# Ajoute tous les sous-dossiers de src/include comme chemins d'includes
CXXFLAGS = -Wall -Wextra -std=c++20 $(shell find Headers/inc -type d | sed "s/^/-I/") $(shell find src/include -type d | sed "s/^/-I/") -I"src/include"
# Utilise les fichiers d'importation présents dans src/lib pour l'édition de liens
LDFLAGS = -L"src/lib" -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lm

# Recherche récursive des fichiers .cpp dans Sources/src et main.cpp
SRC = main.cpp $(shell find Sources/src -name "*.cpp")
OBJ = $(SRC:.cpp=.o)
TARGET = DuckDuckGame.exe

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del /Q $(OBJ) $(TARGET)

.PHONY: all clean

#Merci à Ismael pour l'aide à la compilation sur Windows <3