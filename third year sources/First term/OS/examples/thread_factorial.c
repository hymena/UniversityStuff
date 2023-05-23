#include<pthread.h>
#include<stdio.h>

int result;

void *factorial(void *param)
{
	result = 1;
	int n = *(int*)param;

	while(n>0)
	{
		result *= n;
		n--;
	}
	pthread_exit(0);
}

int main()
{
	pthread_t tid;
	pthread_attr_t attr;
	int n ;

	scanf("%d",&n);

	pthread_attr_init(&attr);
	pthread_create(&tid,&attr,factorial,&n);
	pthread_join(tid,NULL);
	printf("%d",result);

	return 0
;
}


