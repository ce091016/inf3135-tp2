CC = gcc
CFLAGS = -Wall
LFLAGS =
LIB = -ljansson
EXEC = tp2
CURRENT_DIR = $(notdir$(shell pwd))
BIN_PATH = $(CURRENT_DIR)bin
SRC_PATH = $(CURRENT_DIR)src
OBJ_PATH = $(CURRENT_DIR)obj
SRC = $(wildcard $(SRC_PATH)/*.c)
OBJECTS = $(SRC:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)


$(BIN_PATH)/$(EXEC): $(OBJECTS)
	@$ $(CC) -o $@ $(OBJECTS) $(LIB)

$(OBJECTS): $(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@$ $(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean test data

data:
	git pull--recurse-submodules
	git submodule update --remote --recursive

clean:
	rm -f $(BIN_PATH)/$(EXEC)
	rm -f $(OBJ_PATH)/*.o
	rm -f *.txt
	rm -f *.dot
	rm -f *.png

test: test1
	
test1: 
	bats test/testJLH.bats
