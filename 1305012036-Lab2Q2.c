#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<ctype.h>

int main()
{
int numberOfLetters;
int numberOfNumbers;

FILE *file;
int c;
pid_t pid = fork();

if(pid > 0 ){
printf("[PARENT] Child process ID: %d \n",(int)pid);
}

if(pid == 0){
	file = fopen("data.txt","r");
	while((c = fgetc(file)) != EOF){
		
	if(isalpha((char)c))
		numberOfLetters++;
	}
fclose(file);
printf("[Child1] Number of letters: %d \n",numberOfLetters);

pid_t pid2 = fork();

	if(pid2 > 0 ){
	printf("[PARENT] Child process ID: %d \n",(int)pid2);
		
	}
	
	if(pid2 == 0){
	file = fopen("data.txt","r");
	while((c = fgetc(file)) != EOF){
		
	if(!isalpha((char)c))
		numberOfNumbers++;
	
}
printf("[Child2] Number of numbers: %d\n",100000-numberOfLetters);
	}
   
}
return 0;
}
