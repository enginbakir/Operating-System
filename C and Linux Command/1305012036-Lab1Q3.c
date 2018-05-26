#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){

//srand(time(NULL));     // if you want to see the different random numbers, delete the comment syntax of srand(time(NULL)) function

int matrix[10][10];
int i=0;
int k=0;
for(i=0;i<10;i++){

		for(k=0;k<10;k++){
			matrix[i][k] = rand()%10000;
			printf("%d ",matrix[i][k]);
		}
	printf("\n");
}
return 0;
}

/// The Command Line ///

/* 
gcc -o question3 1305012036-Lab1Q3.c

./question3 

./question3 | sort -n -k3  > sorted.txt 

cat sorted.txt
*/


