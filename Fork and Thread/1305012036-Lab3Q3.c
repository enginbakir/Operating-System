#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
char * gettline();
char * splitstr();

	int main(){

	srand(time(NULL));

	FILE *file1;
	FILE *file2;
	char *nameOfFile1;
	char *nameOfFile2;
	int number1;
	int number2;
	char *string = gettline();
	int i = 0;
		
		/// CHECKING THE INPUT ///

	if(string != NULL){

	if((nameOfFile1 = strsep(&string," ")) != '\0')
		printf("\t");
	else{
		printf("enter inputs correctly\n");
		exit(getpid());
	}
	if((nameOfFile2 = strsep(&string," ")) != '\0')
		printf("\t");
	else{
		printf("enter inputs correctly\n");
		exit(getpid());
	}
	if((number1 = atoi(strsep(&string," "))) != '\0')
		printf("\t");
	
	else{
		printf("enter inputs correctly\n");
		exit(getpid());
	}
	if((number2 = atoi(strsep(&string," "))) != '\0')
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
		int r;
				/// FILE 1 ///
			file1 = fopen(nameOfFile1,"w+");
		printf("[CHILD1] Writing %d random integers to %s...\n",number1,nameOfFile1);	
			for(i;i<number1;i++){
			r=rand()%1000;
			fprintf(file1,"%d",r);
			fprintf(file1,"\n");
			//printf("%d\n",r);
			}
		fclose(file1);
				
	exit(EXIT_SUCCESS);
	}
	if(pid1>0){	
}

		/// CHILD 2 ////

	printf("[PARENT] Creating Second Child Process...\n");
wait(NULL);
	pid_t pid2 = fork();			
	
		if(pid2 == 0){	
int r;				
				/// FILE 2 ///
		srand(time(NULL));
			file2 = fopen(nameOfFile2,"w+");
		printf("[CHILD2] Writing %d random integers to %s...\n",number2,nameOfFile2);	
			for(i;i<number2;i++){
			r=rand()%1000;
			fprintf(file2,"%d",r);
			fprintf(file2,"\n");
			//printf("%d\n",r);
			}
		fclose(file2);				
					
	exit(EXIT_SUCCESS);
	}
	
	
		
		
int status;
int endpid;
if(pid2>0){
while(1){

endpid = waitpid(pid2,&status,WNOHANG | WUNTRACED);
if(endpid == pid2){
/// CHILD 3 ////
printf("[PARENT] Creating Third Process...\n");	
pid_t pid3 = fork();
	
		if(pid3 == 0){
		printf("[CHILD3] Sorting Both Files:\n");	
			char command[50];
			strcpy(command,"sort -n ");
			strcat(command,nameOfFile1);
			strcat(command," ");	
			strcat(command,nameOfFile2);
			system(command);
			
		exit(getpid());
		}

wait(NULL);
	break;
}
}



}	


printf("[PARENT] DONE\n");	
exit(EXIT_SUCCESS);
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
