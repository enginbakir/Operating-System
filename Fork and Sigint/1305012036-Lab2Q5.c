#include <stdio.h> 
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

void ctrl_c(int);
int boolean=1;
int count=0;
	int main(){
		srand(time(NULL));
		

	(void)signal(SIGINT, ctrl_c);

	while(1){
	
if(boolean == 1 && count <= 15){
	printf("%d\n",rand()%10);
	sleep(1);
	count++;

	}

else if(boolean == 0 && count <= 15){

	int r = rand()%26;
	char c = (char) r+65;
	printf("%c\n",c);
	sleep(1);
	count++;		
	
}
else {
printf("End");
break;
}
}
}
	void ctrl_c(int signum){
 // (void)signal(SIGINT, ctrl_c);
	if(boolean == 1)
		boolean	= 0;
	else 
		boolean = 1;
printf("\n");
count=0;

}
