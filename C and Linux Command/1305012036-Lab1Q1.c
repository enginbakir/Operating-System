#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
srand(time(NULL));
int x,y;
printf("enter two integer \n\n");
scanf("%d",&x);
scanf("%d",&y);
int matrix[x][y];
int i=0;
int k=0;
FILE *fp;

fp = fopen("numbers.txt","w+");
	for(i=0;i<x;i++){

		for(k=0;k<y;k++){
			matrix[i][k] = rand()%100;
			fprintf(fp,"%d ",matrix[i][k]);
			
			
		}
		fprintf(fp,"\n");
	}



	fclose(fp);
return 0;
}


/// The Command Line ///

/* 
gcc -o question1 1305012036-Lab1Q1.c

./question1

cat numbers.txt 
*/
