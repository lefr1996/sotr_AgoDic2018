#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

#define NUM_THREADS 5

void *PrintHello(void *threadid) {
	long tid;
	tid = (long)threadid;
	printf("Hello World! Thread ID, %d",tid);
	pthread_exit(NULL);}

int main () {
	pthread_t threads[NUM_THREADS];
	int rc;
	int i;
	for( i = 0; i < NUM_THREADS; i++ ) {
		printf("main() : creating thread, %d",i);
		rc = pthread_create(&threads[i], NULL, PrintHello, (void *)(long)i);
		if (rc) {
			printf("Error:unable to create thread, %d",rc);
			exit(-1);}}
	pthread_exit(NULL);}
