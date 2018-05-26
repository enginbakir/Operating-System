#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
 
#define NUM_THREADS 10
#define arrayLength 10000
int array[arrayLength];
int threadMap[arrayLength];
int primesPerThread[NUM_THREADS];
int ten=10;
int c = 0;

  int is_prime(int n){
	
	
	int k=0;
	int j=0;

    for(j=1;j <= n;j++){
	if((n%j)==0){
		k++;
	}
    }

	if(k == 2){ 
		return 1;
	}
	else{
		return 0;
	}
  }

  void* findPrimes(void* argument){

	int passed_in_value;
		passed_in_value = *((int*) argument);
	int position = threadMap[passed_in_value]; 
	int numberOfPrime=0;
		ten = position + 10;	
	for(position;position < ten;position++){
		if(is_prime(array[position]) == 1){			
			numberOfPrime++;
		}
 	}
	threadMap[passed_in_value] = threadMap[passed_in_value] + 100;
	primesPerThread[passed_in_value] = numberOfPrime + primesPerThread[passed_in_value];	
	return NULL;
}

		///	GENERATE RANDOM ARRAY	///

  void* generateRandomArray() {		
	
	int i=0;	
	while(i < arrayLength){
		array[i]=(int)rand()%10000;
	if(array[i]<1000)
		array[i]=array[i]+1000;		
	i++;					
	}
  	return NULL;
  }
 		///	MAIN	///

int main(int argc, char** argv) {

int i=0;

  pthread_t threads[NUM_THREADS];
  int thread_args[NUM_THREADS];
  int result_code;
  unsigned index;

srand(time(NULL));
generateRandomArray();

for(index =0;index< NUM_THREADS;index++){
	thread_args[index] = index;
	threadMap[arrayLength] = index*10;
}
	for(index = 0;index <100;index++){ 
		for(i=0;i<10;i++){
			pthread_create(&threads[i], NULL, findPrimes, &thread_args[i]);
		}
	}

	for(i=0;i<10;i++){
		pthread_create(&threads[i], NULL, findPrimes, &thread_args[i]);
	}
 
for(i=0;i<NUM_THREADS;i++)
printf("Thread %d - %d primes.\n",i,primesPerThread[i]);

  exit(EXIT_SUCCESS);
}
