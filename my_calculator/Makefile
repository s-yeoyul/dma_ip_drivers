CC = gcc
CFLAGS = -Wall -g

TARGET = my_calculator

OBJS = my_calculator.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

main.o: my_calculator.c
	$(CC) $(CFLAGS) -c my_calculator.c


