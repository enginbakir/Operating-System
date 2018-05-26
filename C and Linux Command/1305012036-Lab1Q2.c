#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){

srand(time(NULL));

FILE *fp;

fp = fopen("numbers2.txt","w+");

int i=0;
int random=0;
	for(i=1;i<=1000;i++){
		random=rand()%1000+100;
			if(random>1000)
			random=random-100;
		fprintf(fp,"%d",random);
		fprintf(fp,"\n");

	}
	fclose(fp);
return 0;
}

/// The Command Line ///

/* gcc -o question2 1305012036-Lab1Q2.c

./question2

 cat numbers2.txt | grep "^2" 
*/


