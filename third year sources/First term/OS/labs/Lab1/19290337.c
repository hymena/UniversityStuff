#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<wait.h>
#include<unistd.h>

int main()
{
	int SharedMemId;
	int *SharedMemPTR;
	int ChildProcessId;
	// Getting the numbers from input
	int number,number1,number2,number3;
	scanf("%d",&number);
	scanf("%d",&number1);
	scanf("%d",&number2);
	scanf("%d",&number3);
	
	//Allocating the shared memmory
	SharedMemId = shmget(IPC_PRIVATE, 4*sizeof(int), IPC_CREAT | 0666);
	// If returned value less than zero allocating shared memory failed
	if(SharedMemId < 0){
		printf("an error occured while setting shared memory");
		return -1;
	}

	printf("Server has received a shared memory of four integers...\n");

	// Getting the address that shared memmory starts
	SharedMemPTR = (int *) shmat(SharedMemId, NULL, 0);
	printf("Server has attached the shared memory...\n");
	SharedMemPTR[0] = number;
	SharedMemPTR[1] = number1;
	SharedMemPTR[2] = number2;
	SharedMemPTR[3] = number3;
	// Store the number in shared memory addresses
	printf("Server has filled %d %d %d %d in shared memory...\n",SharedMemPTR[0],SharedMemPTR[1],SharedMemPTR[2],SharedMemPTR[3]);

	// Create a child process
	printf("Server is about to fork a child process...\n");
	
	fflush(stdout);
	ChildProcessId = fork();
	// If returned value less than zero forking child process is failed
	if(ChildProcessId < 0){
		printf("An error occured while creating child process...\n");
		return -1;
	}
	// Child process does not know its own id if it's not specified so it assumes the id as 0
	// When id 0 child process runs
	else if(ChildProcessId == 0){
		printf("   Client process started\n");
		printf("   Client found %d %d %d %d in shared memory\n",SharedMemPTR[0],SharedMemPTR[1],SharedMemPTR[2],SharedMemPTR[3]);
		int sum = SharedMemPTR[0]+SharedMemPTR[1]+SharedMemPTR[2]+SharedMemPTR[3];
		printf("   Client sum of shared integer values %d \n", sum);
		printf("   Client is about to exit\n");
		return 0;
	}
	// When id is gretear than 0 it means parent process is running
	else{
		//Parent process is waiting the child process with the wait call
		wait(NULL);
		printf("Server has detected the completion of its child...\n");
		//Child process execution is done so parent process is start executing again
		int sum = SharedMemPTR[0]+SharedMemPTR[1]+SharedMemPTR[2]+SharedMemPTR[3];
		printf("Parent sum of shared memory %d \n",sum);
		// Detached shared memory
		shmdt((void *) SharedMemPTR);
		printf("Server has detached its shared memory...\n");
		// Close the shared memory
		shmctl(SharedMemId,IPC_RMID,NULL);
		printf("Server has removed its shared memory...\n");
		printf("Server exits...\n");
		return 0;
	}
	
}

