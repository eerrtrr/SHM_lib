// ---------------- IMPORTATIONS ----------------
//standard
#include <stdio.h>
#include <stdlib.h>

//shared memory
#include <sys/shm.h>
#include <sys/stat.h>





// ---------------- SHM TOOLS ----------------

//SHM info struct
struct SHM{
	int shm_id;
	size_t text_length;
	char* shared_memory;
};
typedef struct SHM shm;


//SHM functions
char* shm_pull(shm* mem);

void shm_printData(shm* mem);

void shm_push(char* str, shm* mem);

shm* shm_create(size_t length);
shm* shm_open(int id, size_t length);

void shm_close(shm* mem);
void shm_delete(shm* mem);

int shm_getId(shm* mem);

void clean_buffer();
