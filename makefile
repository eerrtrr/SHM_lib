process: process1.o process2.o shm_lib.o
	gcc -o process1 process1.o shm_lib.o
	gcc -o process2 process2.o shm_lib.o

process1.o : process1.c shm_lib.h
	gcc -c -Wall process1.c

process2.o : process2.c shm_lib.h
	gcc -c -Wall process2.c


shm_lib.o : shm_lib.c shm_lib.h
	gcc -c -Wall shm_lib.c
	
rm :
	rm *.o
