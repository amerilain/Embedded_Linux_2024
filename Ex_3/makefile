random_generator: main.o random.o
	gcc -o random_generator main.o random.o

main.o: main.c
	gcc -c main.c

random.o: random.c 
	gcc -c random.c

clean:
	rm -f *.o random_generator
