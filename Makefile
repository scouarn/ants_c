CC := gcc
CFLAGS := -Wall -Iinclude


SRC := $(wildcard source/*.c)
OBJ := $(patsubst %.c,%.o,$(SRC))
HEADERS := $(wildcard include/*.h)

TARGET := bin/ants
LIBS := -lm -lezgfx-core -lezgfx-common -lpthread

all : $(TARGET)

clean :
	rm -rf $(OBJ) $(TARGET)

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@


$(TARGET) : $(OBJ)
	$(CC) $(CFLAGS) $(LIBS) $^ -o $@