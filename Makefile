SOURCE_NAME = src/tp2
EXEC = tp2
FLAGS = -Wall

$(EXEC): $(SOURCE_NAME).o
	gcc -o $(EXEC) $(SOURCE_NAME).o

$(SOURCE_NAME).o: $(SOURCE_NAME).c
	gcc $(FLAGS) -c $(SOURCE_NAME).c

.PHONY: clean

clean:
		rm *.o
		rm $(EXEC)	
