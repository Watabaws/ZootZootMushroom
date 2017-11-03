dir_reader: dirdunk.o
	gcc -o dir_reader dirdunk.o

dirdunk.o:
	gcc -c dirdunk.c

run: dir_reader
	./dir_reader
