#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
char * gettline();
char * splitstr();

		int main(){	/////	MAİN	/////

	srand(time(NULL));
	FILE *file;
	char *string = gettline();
	char *nameOfFile;
	int number;
	
	int i=0;

	if(string != NULL){

	if((nameOfFile = strsep(&string," ")) != '\0')
		printf("\t");
	else{
		printf("enter inputs correctly\n");
		exit(getpid());
	}
	if((number = atoi(strsep(&string," "))) != '\0')
		printf("\n");
	
	else{
		printf("enter inputs correctly\n");
		exit(getpid());
	}
	if(strsep(&string," ") != NULL){
		printf("too many arguments, ");
		printf("enter inputs correctly\n");
		exit(getpid());
	}
	}
		/// CHILD 1 ///

	printf("[PARENT] Creating First Child Process...\n");
	
	pid_t pid1 = fork();		

	if(pid1 == 0){
	printf("[CHILD1] Creating %s with %d integers...\n",nameOfFile,number);
		file = fopen(nameOfFile,"w+");
			
			for(i;i<number;i++){
			fprintf(file,"%d",rand()%1000);
			fprintf(file,"\n");
			}
		fclose(file);
				
	exit(pid1);
	}



	wait(NULL);

		/// CHILD 2 ////

	printf("[PARENT] Creating Second Child Process...\n");

	pid_t pid2 = fork();		

	if(pid2 == 0){
	printf("[CHILD2] Executing Sort Command...\n");
				
		char command[50];
		strcpy(command,"sort -n ");
		strcat(command,nameOfFile);
		system(command);			
					
	exit(pid2);
	}
	wait(NULL);

		/// CHILD 3////
		
	printf("[PARENT] Creating Third Process...\n");		
	pid_t pid3 = fork();
		if(pid3 == 0){

		int max=0,min=1000;
			char tmp[50];
			
			file = fopen(nameOfFile,"r+");	

			while(fscanf(file,"%s",tmp) == 1){		
			
				if(max < atoi(tmp)){
				max = (int)atoi(tmp);
				}
				if(min > atoi(tmp)){
				min = (int)atoi(tmp);
				}
	}
	printf("[CHILD3] Min: %d, Max: %d ...\n",min,max);

	fclose(file);

	exit(pid3);
	}
	wait(NULL);
	printf("[PARENT] DONE.\n");
	return (0);
	}



char * gettline() {
    char * line = malloc(100), * linep = line;
    size_t lenmax = 100, len = lenmax;
    int c;

    if(line == NULL)
        return NULL;

    for(;;) {
        c = fgetc(stdin);
        if(c == EOF)
            break;

        if(--len == 0) {
            len = lenmax;
            char * linen = realloc(linep, lenmax *= 2);

            if(linen == NULL) {
                free(linep);
                return NULL;
            }
            line = linen + (line - linep);
            linep = linen;
        }

        if((*line++ = c) == '\n')
            break;
    }
    *line = '\0';

    return linep;
}
