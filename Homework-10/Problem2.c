#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int A, B;
double *sum;
void* pi_run(void* arg) {
	
	long C = (long)arg;
	for(int D = (A/B)*(C-1); D < ((A/B)*(C)); D++) {
		
		if(D % 2 == 0) {
			sum[C] += 4.0/((2*C)*(2*C+1)*(2*C+2));
		}
		else {
			sum[C] -= 4.0/((2*C)*(2*C+1)*(2*C+2));
		}
	}
	
	pthread_exit(0);

}

int main(int argc, char **argv) {
	
	if(argc != 3) {
 
		printf("ERROR: Enter a number for term and then the thread %d\n", argc-1);
		exit(1);
   
	}
 
	for(int p=1; p<=B; p++) {
		
		sum[p] = 0;
   
	}

	double pi = 3.141592653589793238;

	pthread_t tids[B+1];

	for(long D = 1; D<=B; D++) {
	
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_create(&tids[D], &attr, pi_run, (void*)D);

	}
	
	for(int E = 1; E<=B; E++) {
		
		pthread_join(tids[E], NULL);
		
	}
	
	for(int F=1; F<=B; F++) {
	
		pi += sum[F];

	}
	
	printf("Pi is %.20f\n", pi);
	free(sum);
}