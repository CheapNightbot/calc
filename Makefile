CC = gcc
CFLAGS = -Wall -g
DIR = build
EXE = $(DIR)/calc
OBJ = $(DIR)/main.o $(DIR)/calc.o

# Target to build the program
calc: $(EXE)

# Create the build directory and link objects to create the executable
$(EXE): $(OBJ)
	@mkdir -p $(DIR)
	$(CC) $(OBJ) -o $(EXE) -lm

# Compile main.o
$(DIR)/main.o: src/main.c src/calc.h
	@mkdir -p $(DIR)
	$(CC) $(CFLAGS) -c src/main.c -o $(DIR)/main.o

# Compile calc.o
$(DIR)/calc.o: src/calc.c src/calc.h
	@mkdir -p $(DIR)
	$(CC) $(CFLAGS) -c src/calc.c -o $(DIR)/calc.o

# Clean target to remove build files
clean:
	rm -rf $(DIR)
