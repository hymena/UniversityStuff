#include<stdio.h>
#include<pthread.h>



int sum; //This variable is shared by the threads


void *runner(int upper)
{
	int i;
	sum = 0;
	for(i=1;i<=x;i++)
		sum+=i;

	pthread_exit(0);
}

int main()
{
	pthread_t thread_id;
	pthread_attr_t attr;

	int input;

	scanf("%d",&input);
	if(input <= 0)
	{
		printf("input must be >=0");
		return -1;
	}

	//create the default attributes for thraed
	pthread_attr_init(&attr);
	//create the thread
	pthread_create(&thread_id,&attr,runner, input);

	//wait for the thread to exit
	pthread_join(thread_id,NULL);

	printf("%d",sum);

	return 0;
}
