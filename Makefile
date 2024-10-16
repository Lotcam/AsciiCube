CC = gcc
CFLAGS = -Wall
SRC = src/asciigl.c src/utils.c
OBJ = $(SRC:.c=.o)
TARGET = build/asciigl

all: $(TARGET)

$(TARGET): $(OBJ)
	mkdir -p build
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

clean:
	rm -rf build/*.o build/asciigl
