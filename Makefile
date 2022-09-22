
Project : main.o fun.o
	gcc main.o fun.o -o Project
main.o : main.c
	gcc -c main.c -o main.o
fun.o : fun.c
	gcc -c fun.c -o fun.o
clean : 
	rm Project *.o