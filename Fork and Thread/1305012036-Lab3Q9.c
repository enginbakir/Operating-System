#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#define NUM_THREADS 10
#define arrayLength 50000

pthread_mutex_t mutex;
int digits[NUM_THREADS];
int numberOfVowel[NUM_THREADS];
int numberOfConsonant[NUM_THREADS];
char array[arrayLength];
long threadID[NUM_THREADS];
int a=0;
int c=0;
int fifth=50;

int threadMap[NUM_THREADS];

int isVowelOrConsonant(char c){
if(c == 'a' || c == 'o' || c == 'e' || c == 'i' || c == 'u')
return 1;
else
return 0;
}

void *countVowelAndConsonant(void* argument){

	if(a<NUM_THREADS){
		threadID[a%NUM_THREADS] = pthread_self();
		a++;
	}
	int passed_in_value;
	passed_in_value = *((int*) argument);
	int position= threadMap[passed_in_value]; 

	fifth = position+10;

	for(position;position < fifth;position++){
		if(isVowelOrConsonant(array[position]) == 1)
			numberOfVowel[passed_in_value]++;
		else
			numberOfConsonant[passed_in_value]++;
 	}
	threadMap[passed_in_value] = threadMap[passed_in_value]+100;
return NULL;
}

 void* generateRandomCharArray() {
  	 
	int r;
	int i=0;	

	while(i < arrayLength){
		r = rand()%26;
		array[i] = tolower((char) r+65);	
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
  generateRandomCharArray();
for(index = 0;index < NUM_THREADS;index++){
    thread_args[index] = index;
	threadMap[index] = index*NUM_THREADS;

}
for(index = 0;index <arrayLength/(NUM_THREADS*NUM_THREADS);index++){ 
	for(i = 0;i<NUM_THREADS;i++){
		result_code = pthread_create(&threads[i], NULL, countVowelAndConsonant, &thread_args[i]);
	}
}
for(i = 0;i<NUM_THREADS;i++){
	result_code = pthread_join(threads[i], NULL);
}

for(index=0;index<NUM_THREADS;index++)
 	printf("Thread %ld: Vowels: %d, Consonant: %d\n",threadID[index],numberOfVowel[index],numberOfConsonant[index]);

  exit(EXIT_SUCCESS);
}
