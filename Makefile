

tp2: bin/tp2.o
	gcc -o bin/tp2 tp2.o
	rm tp2.o
bin/tp2.o: src/tp2.c
	gcc -c src/tp2.c


.PHONY: clean

clean:
		rm -f *.o
		rm -f tp2
