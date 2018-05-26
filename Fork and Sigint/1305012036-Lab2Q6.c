#include <stdio.h> 
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

	int main(){

FILE *file;

pid_t pid = fork();
pid_t pid2;

if(pid == 0){
	int i = 0;
	file = fopen("data1.txt","w+");
	printf("[CHILD1] wrote: ");
	while(i < 10){
		int num = rand()%10;
		fprintf(file,"%d",num);
		printf("%d ",num);
		i++;
}

printf("to file.\n");
fclose(file);
exit(0);
}


if(pid > 0){
	printf("[PARENT] Child process ID: %d \n",(int)pid);
	pid2 = fork();
	
}

if(pid2 > 0){
	printf("[PARENT] Child process ID: %d \n",(int)pid2);
	wait(NULL);
}
if(pid2 == 0 ){

	int j = 0;
	file = fopen("data2.txt","w+");
	printf("[CHILD2] wrote: ");
	while(j < 10){
		int r = rand()%26;
		char c = (char) r+65;
		fprintf(file,"%c",c);
		printf("%c ",c);
		j++;

	}
printf("to file.\n");
fclose(file);
exit(0);

}

wait(NULL);

FILE *f1,*f2;
f1=fopen("data1.txt","r");
f2=fopen("data2.txt","r");

char c1;
char c2;
printf("[PARENT] ");
		while(1){
		c1 = fgetc(f1);
		c2 = fgetc(f2);
			if(c1 == EOF | c2 == EOF)
				break;
			else{
				printf("%c %c ",c1,c2);
			}
		}
printf("\n");

fclose(f1);
fclose(f2);

return 0;
}
