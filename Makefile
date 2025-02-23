CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c11

OUTPUT = money_converter
SOURCE_FILES = main.c memoize.c 

all: $(OUTPUT)

$(OUTPUT): $(SOURCE_FILES) memoize.h  
	$(CC) $(CFLAGS) -o $(OUTPUT) main.c memoize.c 

clean:
	rm -f $(OUTPUT)
