#include<stdio.h>
#include<signal.h>
#include<stdlib.h>


static void sig_handler(){

	printf("I received SIGINT signal. Byeee...\n");
	fflush(stdout);
	exit(0);
}


int main(){

	signal(SIGINT, sig_handler);

	while(1)
		printf("running\n");

	return 0;
}
