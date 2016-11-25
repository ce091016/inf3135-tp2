#CURRENT_DIR = $(notdir$(shell pwd))
#EXEC_PATH = $(CURRENT_DIR)bin
#FILE = tp2
#SRC_PATH = $(CURRENT_DIR)src
#CFLAGS = -Wall 


#$(FILE): $(FILE).o
#	gcc -o $(EXEC_PATH)/$(FILE) $(FILE).o
#	mv *.o $(EXEC_PATH)

#$(FILE).o: $(SRC_PATH)/$(FILE).c
#	gcc $(CFLAGES) -c $(SRC_PATH)/$(FILE).c

#.PHONY: clean

#clean:
#		rm -f $(EXEC_PATH)/*.o
#		rm -f $(EXEC_PATH)/$(FILE)
#
#

exe: test.o countries.o input.o graphviz.o
	gcc -o exe test.o countries.o input.o graphviz.o -ljansson
	rm -f *.o
test.o: test.c
	gcc -c test.c

countries.o: countries.c
	gcc -c countries.c

input.o: input.c
	gcc -c input.c

graphviz.o: graphviz.c
	gcc -c graphviz.c
