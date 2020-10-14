// ---------------- IMPORTATIONS ----------------
#include "shm_lib.h"




// ---------------- SHM TOOLS ----------------


char* shm_pull(shm* mem){
	char* data = (char*) shmat(mem->shm_id, 0, 0);		
	return data;
}

void shm_printData(shm* mem){
	char* data = (char*) shmat(mem->shm_id, 0, 0);
	printf("%s\n", data);
}



void shm_push(char* str, shm* mem){
	sprintf(mem->shared_memory, "%s", str);
}



shm* shm_create(size_t length){
	shm* mem = malloc(sizeof(shm));
	mem->shm_id = shmget(IPC_PRIVATE, length, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
	mem->text_length = length;
	mem->shared_memory = (char*) shmat (mem->shm_id, 0, 0);
	
	return mem;
}

shm* shm_open(int id, size_t length){
	shm* mem = malloc(sizeof(shm));
	mem->shm_id = id;
	mem->text_length = length;
	mem->shared_memory = (char*) shmat (mem->shm_id, 0, 0);
	
	return mem;
}



void shm_close(shm* mem){
	shmdt(mem->shared_memory);
	free(mem->shared_memory);
	free(mem);
}

void shm_delete(shm* mem){
	shmctl(mem->shm_id, IPC_RMID,0);
	shmdt(mem->shared_memory);
	free(mem);
}



int shm_getId(shm* mem){
	return mem->shm_id;
}



void clean_buffer(){
	int ch;
	do{
		ch = fgetc(stdin);
	}while(ch != EOF && ch != '\n');
}
