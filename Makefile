# --------------------------------------------------------------------
CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic -Iinclude
OBJ     = better_types.o large_num.o main.o
SRCS    := src/better_double_math.c src/large_num_math.c example.c
OBJS    := $(SRCS:.c=.o)
TARGET  := example
# --------------------------------------------------------------------
$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $@

# pattern rule: turn each .c into a .o in the same folder
%.o: %.c include/better_types.h
	$(CC) $(CFLAGS) -c $< -o $@

debug: CFLAGS += -g

debug : $(OBJS) 
	$(CC) $(OBJS) $(LDFLAGS) -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)
	rm -f debug