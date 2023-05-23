#include<pthread.h>
#include<stdio.h>

int sum; //shared sum between thrads

void *runner(void *param){
	int i;
	int upper;
	upper = *(int*)param;
	sum = 0;
	for(i=1;i<=upper;i++)
		sum+=i;

	pthread_exit(0);
}
int main()
{

	pthread_t thread_id; // id of the thread that will created
	pthread_attr_t attr; // set of thread attributes

	int num;
	scanf("%d",&num);
	pthread_attr_init(&attr);
	pthread_create(&thread_id,&attr,runner,&num);
	pthread_join(thread_id,NULL);
	printf("%d\n",sum);


	return 0;
}
