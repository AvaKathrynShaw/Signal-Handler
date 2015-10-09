CC = gcc
CFLAGS = -O0 -g3 -m32

SRC = undead_code.c
OBJS = $(SRC:.c=.o)

TARGET = undead_code
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

clean:
	$(RM) $(OBJS)