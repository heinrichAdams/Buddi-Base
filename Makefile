# Makefile Variables

Compiler = gcc
STD = -std=c99
C_Flags = -Wall -Wfatal-errors 
SRC = ./src/*.c ./src/Demo/*.c
L_Flags = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
Output = Demo

# Makefile Rules

build:
	$(Compiler) $(C_Flags) $(STD) $(SRC) $(L_Flags) -o $(Output)

run:
	./$(Output)

clean:
	rm $(Output)