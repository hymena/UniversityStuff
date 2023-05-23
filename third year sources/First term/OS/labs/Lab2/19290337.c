#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t x;
float sum = 0;
int lines = 0;
float array[1024];
int current = 0;
int threads = 5;
int lines_per_thread[5] = {0,0,0,0,0};

void *thread(void *parameter)
{
	sem_wait(&x);// decrease the semaphore so no other thread can involve
	int i = 0;
	// current variable indicates the index in the array that stores the corresponding line in the file.For example if current = 3, that corresponds to third line 
	// until reaching the maximum lines in the file, increment current line
	while (i < lines_per_thread[ *(int *)parameter] )
	{
		sum += array[current];
		printf("Thread %d reads %d. line. The value is %.2f \n", *(int *)parameter + 1,current, array[current++]);
		i++;
	}
	
	printf("Shared Resource: %.2f\n",sum);
	sem_post(&x); // after critical section increment the semaphore
	pthread_exit(0);
}

int main(int argc, char **argv)
{

	while (scanf("%f", &array[lines]) != EOF) // to calculate  the number of lines in the file count the lines, as mentioned in the pdf
	{
		lines++; // each line stored in an array, so that can be used later 
	}

	while (lines>0) // Distrubuting the lines to threads
	{
		for (int i = 0; i < threads; i++)
		{
			lines_per_thread[i]+=1;
			lines--;
			if (lines==0)break;
		}
		
	}
	
	sem_init(&x, 0, 1); // Initialize a semaphore at the location of x and set it visible to all thread of process and inital value is 1
	pthread_t t[threads]; // thread id
	int i, t_args[threads];
	for (i = 0; i < threads; i++) 
	{	
		t_args[i]=i;
		pthread_create(&t[i], NULL, thread, &t_args[i]);// create 5 threads 
	}

	for (i = 0; i < threads; i++) {
        pthread_join(t[i], NULL);
    }

	sem_destroy(&x);
	return 0;
}
