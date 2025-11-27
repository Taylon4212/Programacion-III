# Nombre del ejecutable
TARGET = juego

# Compilador
CXX = g++

# Flags del compilador
CXXFLAGS = -std=c++17 -Wall -Wextra -g -fsanitize=address

# Librerías SFML
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Archivos fuente
SRCS = main.cpp Personaje.cpp menu.cpp escenarios.cpp History.cpp Juego.cpp Inventario.cpp

# Archivos objeto
OBJS = $(SRCS:.cpp=.o)

# Regla principal
all: $(TARGET)

# Enlazar todos los objetos en el ejecutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

# Compilar cada archivo fuente en su objeto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Limpiar archivos generados
clean:
	rm -f $(TARGET) $(OBJS)
