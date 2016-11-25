CC = gcc
CFLAGS = -Wall
LFLAGS =
LIB = -ljansson
LIB_TEST = -lcunit
EXEC = tp2
EXEC_TEST = test_countries
CURRENT_DIR = $(notdir$(shell pwd))
BIN_PATH = $(CURRENT_DIR)bin
SRC_PATH = $(CURRENT_DIR)src
OBJ_PATH = $(CURRENT_DIR)obj
TEST_PATH = $(CURRENT_DIR)test
SRC = $(wildcard $(SRC_PATH)/*.c)
SRC_TEST = $(wildcard $(TEST_PATH)/*.c)
OBJ= $(wildcard $(OBJ_PATH)/*.o)
OBJ_SANS_TP2 = $(filter-out $(TP2_O), $(OBJ))
TP2_O = $(OBJ_PATH)/tp2.o
OBJECTS = $(SRC:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)
OBJECTS_TEST = $(SRC_TEST:$(TEST_PATH)/%.c=$(TEST_PATH)/%.o)
BATS = batsTests.bats

.PHONY: clean test data 

$(BIN_PATH)/$(EXEC): $(OBJECTS) 
	@$ $(CC) -o $@ $(OBJECTS) $(LIB)
$(OBJECTS): $(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@$ $(CC) $(CFLAGS) -c $< -o $@


data:
	git submodule add  https://github.com/ablondin/countries data/countries
	git submodule init 
	git submodule update 

clean:
	rm -f $(TEST_PATH)/$(EXEC_TEST)
	rm -f $(BIN_PATH)/$(EXEC)
	rm -f $(TEST_PATH)/*.o
	rm -f $(OBJ_PATH)/*.o
	rm -f *.txt
	rm -f *.dot
	rm -f *.png
	rm -f $(TEST_PATH)/*.o
	rm -f $(TEST_PATH)/$(EXEC_TEST)

test: $(TEST_PATH)/$(EXEC_TEST) test1 test2

$(TEST_PATH)/$(EXEC_TEST): $(OBJECTS_TEST)
	@$ $(CC) -o $@ $(OBJECTS_TEST) $(LIB_TEST) $(LIB) $(OBJ_SANS_TP2)
 
$(OBJECTS_TEST): $(TEST_PATH)/%.o : $(TEST_PATH)/%.c
	@$ $(CC) $(CFLAGS) -c $< -o $@

test1: 
	bats $(TEST_PATH)/$(BATS)
test2: 
	$(TEST_PATH)/$(EXEC_TEST)
