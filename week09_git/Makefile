SRC_DIR = ./src
OBJ_DIR = ./obj
LIB_DIR = ./lib
BIN_DIR = ./bin
CC = gcc

CFLAGS = -I./include -fPIC
LDFLAGS = -L$(LIB_DIR)
RPATH = -Wl,-rpath,$(LIB_DIR)

SRCS_ALL := $(wildcard $(SRC_DIR)/*.c)
SRCS_LIB := $(filter-out $(SRC_DIR)/myapp.c, $(SRCS_ALL))

OBJS_LIB := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS_LIB))
OBJ_APP := $(OBJ_DIR)/myapp.o

.PHONY: all clean run dirs

all: dirs $(BIN_DIR)/myapp

dirs:
	@mkdir -p $(OBJ_DIR) $(LIB_DIR) $(BIN_DIR)

$(BIN_DIR)/myapp: $(LIB_DIR)/libmyops.so $(OBJ_APP)
	$(CC) $(OBJ_APP) $(LDFLAGS) -lmyops $(RPATH) -o $@

$(LIB_DIR)/libmyops.so: $(LIB_DIR)/libmyops.so.1
	ln -sf libmyops.so.1 $@

$(LIB_DIR)/libmyops.so.1: $(LIB_DIR)/libmyops.so.1.0
	ln -sf libmyops.so.1.0 $@

$(LIB_DIR)/libmyops.so.1.0: $(OBJS_LIB)
	$(CC) -shared -Wl,-soname,libmyops.so.1 -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_APP): $(SRC_DIR)/myapp.c
	$(CC) -I./include -c $< -o $@

run: all
	LD_LIBRARY_PATH=$(LIB_DIR) $(BIN_DIR)/myapp

clean:
	rm -f $(OBJ_DIR)/*.o $(LIB_DIR)/libmyops.so* $(BIN_DIR)/myapp
