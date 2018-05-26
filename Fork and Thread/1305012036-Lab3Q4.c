#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
 
#define NUM_THREADS 10
#define arrayLength 1000

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
else {
return 0;
}
}

  void* generateRandomArray(void* argument) {

  	int passed_in_value;
	passed_in_value = *((int*) argument);

  	int array[arrayLength]; 	
	
	int i=0;
	int tmp=0;	
	int numberOfPrime=0;	
	
	while(i < arrayLength){

		tmp=(int)rand()%10000;
	if(tmp<1000)
	tmp=tmp+1000;
		array[i]=tmp;
			
	if(is_prime(array[i]) == 1)

	numberOfPrime++;

	i++;						
}


	printf("Thread %d - %d primes.\n",passed_in_value,numberOfPrime);	

  	return NULL;
}
 
int main(int argc, char** argv) {
  
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
 
  //printf("In main: All threads completed successfully\n");
  exit(EXIT_SUCCESS);
}
