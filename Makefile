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
OBJ_2 = obj/countries.o obj/graphviz.o obj/input.o obj/output.o obj/util.o
OBJ_SANS_TP2 = $(filter-out $(TP2_O), $(OBJ))
TP2_O = tp2.o
TP2_C = tp2.c
OBJECTS = $(SRC:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)
OBJECTS_TEST = $(SRC_TEST:$(TEST_PATH)/%.c=$(TEST_PATH)/%.o)
OBJECTS_TEST_SANS_TP2 = $(filter-out $(TP2_C), $(OBJECTS_TEST))

#testcomp:
#	$(TEST_PATH)/$(EXEC_TEST): $(OBJECTS_TEST)
#		@$ $(CC) -o $@ $(OBJECTS_TEST) $(LIB_TEST) $(LIB) $(wildcard $(OBJ_PATH)/*.o) 
#	$(OBJECTS_TEST): $(TEST_PATH)/%.o : $(TEST_PATH)/%.c
#		@$ $(CC) $(CFLAGS) -c $< -o $@

#EXECUTABLE TESTS
#$(TEST_PATH)/$(EXEC_TEST): $(OBJECTS_TEST)
#	@$ $(CC) -o $@ $(OBJECTS_TEST) $(LIB_TEST) $(LIB) $(wildcard $(OBJ_PATH)/*.o) 
#$(OBJECTS_TEST): $(TEST_PATH)/%.o : $(TEST_PATH)/%.c
#	@$ $(CC) $(CFLAGS) -c $< -o $@

$(BIN_PATH)/$(EXEC): $(OBJECTS) #EXECUTABLE TP2
	@$ $(CC) -o $@ $(OBJECTS) $(LIB)
$(OBJECTS): $(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@$ $(CC) $(CFLAGS) -c $< -o $@



#AVEC TESTS DU PROF
#$(TEST_PATH)/$(EXEC_TEST): $(OBJECTS_TEST)
#	@$ $(CC) -o $@ $(OBJECTS_TEST) $(LIB_TEST) 

#$(OBJECTS_TEST): $(TEST_PATH)/%.o : $(TEST_PATH)/%.c
#	@$ $(CC) $(CFLAGS) -c $< -o $@

#EXECUTABLE TP2
#$(BIN_PATH)/$(EXEC): $(OBJECTS)
#	@$ $(CC) -o $@ $(OBJECTS) $(LIB)

#$(OBJECTS): $(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
#	@$ $(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean test data

data:
	git pull --recurse-submodules
	git submodule update --remote --recursive

clean:
	rm -f $(BIN_PATH)/$(EXEC)
	rm -f $(OBJ_PATH)/*.o
	rm -f *.txt
	rm -f *.dot
	rm -f *.png
	rm -f $(TEST_PATH)/*.o
	rm -f $(TEST_PATH)/$(EXEC_TEST)

test: test/test_countries test1 test2

test/test_countries: $(OBJECTS_TEST)
	@$ $(CC) -o $@ $(OBJECTS_TEST) $(LIB_TEST) $(LIB) $(OBJ_2)
 
$(OBJECTS_TEST): $(TEST_PATH)/%.o : $(TEST_PATH)/%.c
	@$ $(CC) $(CFLAGS) -c $< -o $@

test1: 
	bats test/batsTests.bats
test2: 
	$(TEST_PATH)/$(EXEC_TEST)
