PROJ_DIR=$(shell pwd)
SRC_DIR=$(PROJ_DIR)/src
INC_DIR=$(PROJ_DIR)/include
BIN_DIR=$(PROJ_DIR)/bin
OBJ_DIR=$(PROJ_DIR)/obj
LIB_DIR=$(PROJ_DIR)/lib

.PHONY: basic all clean

basic_ops: ../lib/libmybasic.a

../lib/libmybasic.a: $(OBJ_DIR)/add.o $(OBJ_DIR)/sub.o $(OBJ_DIR)/mul.o $(OBJ_DIR)/div.o
	ar rcs $@ $^

./obj/%.o: ./src/%.c
	gcc -c $< -o $@ -I../include

clean:
	rm -f ./obj/*.o ../lib/libmybasic.a

