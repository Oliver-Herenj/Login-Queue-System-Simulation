CC = gcc
CFLAGS = -pthread
TARGET = login_queue_system

all: $(TARGET)

$(TARGET): main.c login_queue.c
	$(CC) main.c login_queue.c -o $(TARGET) $(CFLAGS)

clean:
	rm -f $(TARGET)
