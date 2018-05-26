#include <stdio.h> 
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>
	int main(){

srand(time(NULL));
FILE *file;

pid_t pid = fork();
	if(pid > 0){
	printf("[PARENT] Child process ID: %d\n",(int)pid);
	}


	if(pid == 0){
file = fopen("numbers.txt","w+");
	int i = 0;
		while(i < 1000000){
		fprintf(file,"%d\t",rand()%10);
		i++;
}
	fclose(file);
	printf("[CHILD1] Wrote 1000000 integers to numbers.txt, terminating\n");
	
exit(0);
}

wait(NULL);

pid_t pid2 = fork();

	if(pid2 > 0){
	printf("[PARENT] Child process ID: %d \n",(int)pid2);
	}

	if(pid2 == 0){
	int even = 0;
	int odd = 0;
	file = fopen("numbers.txt","r");
	char c;
	int num;
		while(1){
		c = fgetc(file);
		
			if(c == EOF)
			break;
			else if(isspace(c))
			{
			//printf("a");
			}
			else{
			num = (int)c;
			num = num%2;
				if(0 == num){
					even++;
					}
				else{
				odd++;
				}
			}

		}
fclose(file);
printf("[CHILD2] Even numbers:%d, odd numbers: %d, terminating.\n",even,odd);
exit(0);
}
wait(NULL);
printf("[PARENT] terminating,\n");

}
