PROJ_DIR=$(shell pwd)
SRC_DIR=$(PROJ_DIR)/src
INC_DIR=$(PROJ_DIR)/include
BIN_DIR=$(PROJ_DIR)/bin
OBJ_DIR=$(PROJ_DIR)/obj
LIB_DIR=$(PROJ_DIR)/lib
.PHONY: all clean basic_ops advanced_ops


CC=gcc

all: basic_ops advanced_ops $(BIN_DIR)/myapp

$(BIN_DIR)/myapp: $(OBJ_DIR)/myapp.o $(LIB_DIR)/libmybasic.a $(LIB_DIR)/libmyadvanced.a
	$(CC) -o $@ $< -L$(LIB_DIR) -lmybasic -lmyadvanced

basic_ops:
	$(MAKE) -C basic_ops
advanced_ops:
	$(MAKE) -C advanced_ops

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -o $@ -I$(INC_DIR)


clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/myapp $(LIB_DIR)/*.a
	$(MAKE) -C basic_ops clean
	$(MAKE) -C advanced_ops clean

