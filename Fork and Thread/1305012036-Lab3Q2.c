#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
char * gettline();
char * splitstr();

	int main(){

	srand(time(NULL));

	FILE *file;
	char *nameOfFile;
	int number;
	char *string = gettline();
	int i = 0;

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
		printf("too mant arguments, ");
		printf("enter inputs correctly\n");
		exit(getpid());
	}
	}
		
		/// CHILD 1 ///

	printf("[PARENT] Creating First Child Process...\n");
	
	pid_t pid1 = fork();		

		if(pid1 == 0){
		file = fopen(nameOfFile,"w+");
		printf("[CHILD1] Writing %d random chars to %s...\n",number,nameOfFile);	
			for(i;i<number;i++){
			int r = rand()%26;
			char c = (char) r+65;
			fprintf(file,"%c",c);
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
	printf("[CHILD2] Executing Zip Command...\n");
				
		char command[50];
		strcpy(command,"zip ");
		strcat(command,nameOfFile);
		strcat(command," ");
		strcat(command,nameOfFile);
		system(command);			
					
	exit(pid2);
	}
	wait(NULL);
	
		/// CHILD 3////
		
	printf("[PARENT] Creating Third Process...\n");		
	pid_t pid3 = fork();
		if(pid3 == 0){
			printf("[CHILD3] Executing ls Command...\n");	
			
			execl("/bin/ls","/bin/ls","-l",(char*) 0);

	exit(pid3);
	}
wait(NULL);
printf("[PARENT] DONE\n");	
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
