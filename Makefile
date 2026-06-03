CC = gcc
CXX = g++
CFLAGS = -std=c11
CXXFLAGS = -std=c++17

# raylib include ve lib yolları
RAYLIB_CFLAGS = $(shell pkg-config --cflags raylib)
RAYLIB_LIBS = $(shell pkg-config --libs raylib)

BACKEND_SRC = backend/graph.c backend/hash.c backend/queue.c backend/algorithms.c backend/trie.c
BACKEND_OBJ = $(BACKEND_SRC:.c=.o)

FRONTEND_SRC = frontend/gui.cpp
FRONTEND_OBJ = $(FRONTEND_SRC:.cpp=.o)

TARGET = visualizer

all: $(TARGET)

# Backend C dosyalarını gcc ile derle
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Frontend C++ dosyasını g++ ile derle (raylib include path ile)
frontend/gui.o: frontend/gui.cpp
	$(CXX) $(CXXFLAGS) $(RAYLIB_CFLAGS) -c $< -o $@

# Hepsini linkle
$(TARGET): $(BACKEND_OBJ) $(FRONTEND_OBJ)
	$(CXX) $(CXXFLAGS) $(BACKEND_OBJ) $(FRONTEND_OBJ) -o $(TARGET) $(RAYLIB_LIBS)

clean:
	rm -f $(TARGET) $(BACKEND_OBJ) $(FRONTEND_OBJ)

.PHONY: all clean
