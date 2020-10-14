// ---------------- IMPORTATIONS ----------------

#include "shm_lib.h"
#include <string.h>





// --------------- DECLARATIONS ---------------

//text length max to transfer
#define text_length 0x6400

unsigned char run = 1; 




// ---------------- EXECUTION ----------------

int main(int argc, char** argv){
	
	printf("Press w to write on SHM\nPress r to read what's on SHM\nPress e to exit");
	shm* mem = shm_create(text_length);
	if(mem == NULL){
		printf("Failed to allocate memory for shared memory structure\n");
		exit(EXIT_FAILURE);
	}
	
	printf("\n\nSHM id is %i\n", shm_getId(mem));
	printf("\n");
	
	 while(run){
	 
	 	 char choice;
	 	 	 	 
	 	 printf("Make a choice : ");
	 	 scanf(" %c", &choice);	
		
	 	 switch(choice){
	 	 	case 'w':
			 	 printf("What do you want to write on shm : ");
			 	 char str[120];
			 	 clean_buffer();
			 	 scanf(" %[^\n]s", str);
			 	 shm_push(str, mem);
			 	 printf("\n");
			 	 break;
			 
			case 'r':
				printf("%s\n\n", mem->shared_memory);
				break;
				
			case 'e':
				run = 0;
				break;
				
			default:
				printf("This option does not exist\n\n");
				break;
	 	 }
	 	 
	 	 clean_buffer();
	 	 	
	 }
 	 
 	 shm_delete(mem);
 	 
	
 	 return 0;
}
