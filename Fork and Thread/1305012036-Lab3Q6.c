#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
 
#define NUM_THREADS 5
#define arrayLength 2000
int digits[NUM_THREADS];

// index 0 means that number is greater than 0 and smaller than 10, 
// and index 1 means that the number is greater 10 and smaller than 100,
// and goes on like this

void* howManyDigit(int number){
	if(number<10)
		digits[0]++;
	if(number>=10 && number<100)
		digits[1]++;
	if(number>=100 && number<1000)
		digits[2]++;
	if(number>=1000 && number<10000)
		digits[3]++;
	if(number>=10000 && number<=50000)
		digits[4]++;
}
  void* generateRandomArray(void* argument) {

  	int passed_in_value;
	passed_in_value = *((int*) argument);
  	int array[arrayLength]; 	
	
	int i=0;	
	
	while(i < arrayLength){

		array[i]=(int)rand()%50000;
	howManyDigit(array[i]);
	i++;						
}

printf("Thread: %d 1-9:%d, 10-99: %d, 100-999: %d, 1000-9999: %d, 10000-50000: %d\n",passed_in_value,digits[0],digits[1],digits[2],digits[3],digits[4]);
	for(i=0;i<NUM_THREADS;i++)
		digits[i]=0;
  	return NULL;
}
 
int main(int argc, char** argv) {
int i=0;
	for(i=0;i<NUM_THREADS;i++)
		digits[i]=0;

  pthread_t threads[NUM_THREADS];
  int thread_args[NUM_THREADS];
  int result_code;
  unsigned index;
  
  for (index = 0; index < NUM_THREADS; ++index) {
    srand(time(NULL));
    thread_args[ index ] = index;
    result_code = pthread_create(&threads[index], NULL, generateRandomArray, &thread_args[index]);
    assert(!result_code);
  }
 
  for (index = 0; index < NUM_THREADS; ++index) {   
    result_code = pthread_join(threads[index], NULL);
    assert(!result_code);
  }

  exit(EXIT_SUCCESS);
}
