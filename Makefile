CFLAGS ?= -Wall -Wextra -ggdb

TARGET := eac-cksum
SRC := eac-cksum.c main.c
OBJ := $(patsubst %.c,%.o,$(SRC))

all : $(TARGET)

$(TARGET) : $(OBJ)

.PHONY : clean

clean :
	$(RM) $(TARGET) $(OBJ)
