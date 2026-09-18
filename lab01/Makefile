CC = gcc
CFLAGS = -W -Wall
TARGET = exe
OBJECTS = foo.o bar.o main.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJECTS): a.h

clean:
	rm -f *.o $(TARGET)

.PHONY: all clean
