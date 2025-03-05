CC = gcc
CFLAGS = -Wall -Wextra
SOURCES = main.c users.c processes.c help.c log_PATH.c errors_PATH.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = pr2

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^

clean:
	rm -f $(OBJECTS) $(TARGET)

