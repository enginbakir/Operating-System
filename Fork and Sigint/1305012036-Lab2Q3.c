#include <stdio.h> 
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
void ctrl_c(int);
int boolean = 1;

	int main(){
	srand(time(NULL));
	int r = 100+rand()%100;
	printf("[Increasing]\n");

	(void)signal(SIGINT, ctrl_c);
	
	while(r<200 && r>=100){
	sleep(2);	
		
	if(boolean == 1)
	{	
	r+=10;
	
	}

	if(boolean == 0)
	{
	r-=10;
	
	}

printf("Variable: %d \n",r);

}
printf("End\n");
return 0;
}
	void ctrl_c(int signum){

	if(boolean == 1)
	{
	printf("\n[Decreasing]\n");
	boolean = 0;
	}
	else
	{
	printf("\n[Increasing]\n");
	boolean = 1;
	}
}

