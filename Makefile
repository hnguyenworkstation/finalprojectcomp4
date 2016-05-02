#=================================================
# NEEDED PROPERTIES
#=================================================
OBJECTS = body.o star.o space.o universe.o main.o
CFLAGS = -c -g -Wall
FLAGS = -Wall -Werror -ansi -pedantic -g
LIB = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
LINK = -L /usr/lib -I /usr/include
EXECUTABLE = orbit
CC = g++

# ===========================================
# Make the final program
all: $(EXECUTABLE)

# ===========================================
# Creating Executables
orbit: main.o universe.o star.o space.o body.o
	@echo '' # New line
	@echo ' ------ 	 target: $@'
	$(CC) $(FLAGS) main.o universe.o body.o star.o space.o -o $(EXECUTABLE) $(LINK) $(LIB)

# ===========================================
# Creating objects
body.o: body.cpp body.hpp SpaceObject.hpp
	@echo '' # New line
	@echo ' ------ Building target: $@'
	$(CC) $(CFLAGS) body.cpp -o body.o

# ===========================================
# Creating objects
star.o: Star.cpp Star.hpp SpaceObject.hpp
	@echo '' # New line
	@echo ' ------ Building target: $@'
	$(CC) $(CFLAGS) Star.cpp -o star.o

# ===========================================
# Creating objects
universe.o: Universe.cpp Universe.hpp Star.hpp body.hpp
	@echo '' # New line
	@echo ' ------ Building target: $@'
	$(CC) $(CFLAGS) Universe.cpp -o universe.o

# ===========================================
# Creating objects
space.o: SpaceObject.cpp SpaceObject.hpp
	@echo '' # New line
	@echo ' ------ Building target: $@'
	$(CC) $(CFLAGS) SpaceObject.cpp -o space.o

# ===========================================
# Creating objects
main.o: main.cpp Universe.hpp
	@echo '' # New line
	@echo ' ------ Building target: $@'
	$(CC) $(CFLAGS) main.cpp -o main.o


clean:
	rm -rf *.o test $(EXECUTABLE)

