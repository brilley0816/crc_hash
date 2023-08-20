DIR_INC = ./include
DIR_OUT_INC = ../yanbrilley_sdk/include
DIR_SRC = ./source
DIR_OBJ = ./build

SRC = $(wildcard $(DIR_SRC)/*.c)
OBJ = $(patsubst %.c, $(DIR_OBJ)/%.o, $(notdir $(SRC)))

TARGET = myprogram

CC = gcc
CFLAGS = -Wall -Wextra -I$(DIR_INC) -I$(DIR_OUT_INC)

$(TARGET):$(OBJ)
	$(CC) $^ -o $@

$(DIR_OBJ)/%.o:$(DIR_SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY:clean

clean:
	find $(DIR_OBJ) -name *.o -exec rm -rf {} \;
	rm ${TARGET};
