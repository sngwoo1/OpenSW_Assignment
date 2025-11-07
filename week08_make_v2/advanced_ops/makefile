PROJ_DIR=$(shell pwd)
SRC_DIR=$(PROJ_DIR)/src
INC_DIR=$(PROJ_DIR)/include
BIN_DIR=$(PROJ_DIR)/bin
OBJ_DIR=$(PROJ_DIR)/obj
LIB_DIR=$(PROJ_DIR)/lib
.PHONY: basic all clean

advanced_ops: ../lib/libmyadvanced.a

../lib/libmyadvanced.a: $(OBJ_DIR)/mymod.o $(OBJ_DIR)/mypow.o
	ar rcs $@ $^

./obj/%.o: ./src/%.c
	gcc -c $< -o $@ -I../include

clean:
	rm -f ./obj/*.o ../lib/libmyadvanced.a

