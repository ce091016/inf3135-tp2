CURRENT_DIR = $(notdir$(shell pwd))
#CURRENT_DIR = $(CURDIR)
EXEC_PATH = $(CURRENT_DIR)bin
FILE = tp2
SRC_PATH = $(CURRENT_DIR)src
CFLAGS = -Wall 

#tp2: tp2.o
#	gcc -o bin/tp2 tp2.o  
#	mv *.o $(CURRENT_DIR)/bin
#
#tp2.o: src/tp2.c
#	gcc -c src/tp2.c


$(FILE): $(FILE).o
	gcc -o $(EXEC_PATH)/$(FILE) $(FILE).o
	mv *.o $(EXEC_PATH)

$(FILE).o: $(SRC_PATH)/$(FILE).c
	gcc $(CFLAGES) -c $(SRC_PATH)/$(FILE).c

.PHONY: clean

clean:
		rm -f $(EXEC_PATH)/*.o
		rm -f $(EXEC_PATH)/$(FILE)
