# Target to build the final executable 'random_generator'
# 'main.o' and 'random.o  are the object files for main.c and random.c
random_generator: main.o random.o
	gcc -o random_generator main.o random.o

# Rule to compile 'main.c' into the object file 'main.o'
# The '-c' flag tells gcc to compile but not link the object file
main.o: main.c
	gcc -c main.c

# Rule to compile 'random.c' into the object file 'random.o'
random.o: random.c 
	gcc -c random.c

# Clean target to remove all object files and the executable
# The '-f' flag ensures there are no errors if the files do not exist
clean:
	rm -f *.o random_generator
