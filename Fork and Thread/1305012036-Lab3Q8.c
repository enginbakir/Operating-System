#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#define NUM_THREADS 10
#define arrayLength 5000
pthread_mutex_t mutex;
int digits[NUM_THREADS];
int numberOfVowel;
int numberOfConsonant;
// index 0 means that number is between 0 and 10 , 
// and others are similar to index 0 

int isVowelOrConsonant(char c){
if(c == 'a' || c == 'o' || c == 'e' || c == 'i' || c == 'u')
return 1;
else
return 0;

}

  void* generateRandomCharArray(void* argument) {
pthread_mutex_lock(&mutex);
numberOfVowel = 0;
numberOfConsonant = 0;
  	char array[arrayLength]; 	
	int r;
	int i=0;	

	while(i < arrayLength){
		r = rand()%26;
		array[i] = tolower((char) r+65);	
	if(isVowelOrConsonant(array[i]) == 1)
	numberOfVowel++;
	else
	numberOfConsonant++;
	i++;						
}
pthread_mutex_unlock(&mutex);
printf("Thread: %ld Vowel: %d, Consonant: %d\n",pthread_self(),numberOfVowel,numberOfConsonant);
  	return NULL;
}
 
int main(int argc, char** argv) {

	if(pthread_mutex_init(&mutex,NULL)!= 0){
	printf("\nMutex failed\n");
	return 1;
  }
  pthread_t threads[NUM_THREADS];
  //int thread_args[NUM_THREADS];
  int result_code;
  unsigned index;
  
  for (index = 0; index < NUM_THREADS; ++index) {

    srand(time(NULL));
    //thread_args[ index ] = index;
    result_code = pthread_create(&threads[index], NULL, generateRandomCharArray, NULL);
    assert(!result_code);
  }
 
  for (index = 0; index < NUM_THREADS; ++index) {   
    result_code = pthread_join(threads[index], NULL);
    assert(!result_code);
  }

  exit(EXIT_SUCCESS);
}
