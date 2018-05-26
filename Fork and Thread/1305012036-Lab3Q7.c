#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
 
#define NUM_THREADS 5
#define arrayLength 10000
#define column 6

int array[arrayLength];
int threadMap[arrayLength];
int ThreadAndDigits[NUM_THREADS][column];  // index 0 means that number is between 0 and 10, and others are similar to index 0 
int fifth=50;
int c = 0;
void* howManyDigit(int number,int passed_in_value){
	if(number<10)
		ThreadAndDigits[passed_in_value][1]++;
	if(number>=10 && number<100)
		ThreadAndDigits[passed_in_value][2]++;
	if(number>=100 && number<1000)
		ThreadAndDigits[passed_in_value][3]++;
	if(number>=1000 && number<10000)
		ThreadAndDigits[passed_in_value][4]++;
	if(number>=10000 && number<=50000)
		ThreadAndDigits[passed_in_value][5]++;
}

void* countDigits(void* argument){


	int passed_in_value;
	passed_in_value = *((int*) argument);
	int position= threadMap[passed_in_value]; 

	fifth = position + 50;
	for(position;position < fifth;position++){
	howManyDigit(array[position],passed_in_value);
  }


threadMap[passed_in_value] = threadMap[passed_in_value]+250;
	return NULL;
}

  void* generateRandomArray() {	
	
	int i=0;	
	
	while(i < arrayLength){
		array[i]=(int)rand()%50000;
	i++;						
}
  	return NULL;
}
 
int main(int argc, char** argv) {

  pthread_t threads[NUM_THREADS];
  int thread_args[NUM_THREADS];
  int result_code;
  int i;
  unsigned index;
 srand(time(NULL));
 generateRandomArray();


for(index = 0;index< NUM_THREADS;index++){
    thread_args[index] = index;
    ThreadAndDigits[index][0]=index;
threadMap[index] = index*50;
}


for(index = 0;index <arrayLength/250;index++){ 
for(i=0;i<NUM_THREADS;i++){
result_code = pthread_create(&threads[i], NULL, countDigits, &thread_args[i]);
}
}

for(i=0;i<NUM_THREADS;i++){

result_code = pthread_join(threads[i], NULL);
}



printf("Thread: %d 1-9:%d, 10-99: %d, 100-999: %d, 1000-9999: %d, 10000-50000: %d\n",ThreadAndDigits[0][0],ThreadAndDigits[0][1],ThreadAndDigits[0][2],ThreadAndDigits[0][3],ThreadAndDigits[0][4],ThreadAndDigits[0][5]);
printf("Thread: %d 1-9:%d, 10-99: %d, 100-999: %d, 1000-9999: %d, 10000-50000: %d\n",ThreadAndDigits[1][0],ThreadAndDigits[1][1],ThreadAndDigits[1][2],ThreadAndDigits[1][3],ThreadAndDigits[1][4],ThreadAndDigits[1][5]);
printf("Thread: %d 1-9:%d, 10-99: %d, 100-999: %d, 1000-9999: %d, 10000-50000: %d\n",ThreadAndDigits[2][0],ThreadAndDigits[2][1],ThreadAndDigits[2][2],ThreadAndDigits[2][3],ThreadAndDigits[2][4],ThreadAndDigits[2][5]);
printf("Thread: %d 1-9:%d, 10-99: %d, 100-999: %d, 1000-9999: %d, 10000-50000: %d\n",ThreadAndDigits[3][0],ThreadAndDigits[3][1],ThreadAndDigits[3][2],ThreadAndDigits[3][3],ThreadAndDigits[3][4],ThreadAndDigits[3][5]);
printf("Thread: %d 1-9:%d, 10-99: %d, 100-999: %d, 1000-9999: %d, 10000-50000: %d\n",ThreadAndDigits[4][0],ThreadAndDigits[4][1],ThreadAndDigits[4][2],ThreadAndDigits[4][3],ThreadAndDigits[4][4],ThreadAndDigits[4][5]);




 
  exit(EXIT_SUCCESS);
}
