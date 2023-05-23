#include<stdio.h>
#define SIZE 10
#define MAX 10000

int previous[SIZE];
int isVisited[SIZE];
int distanceList[SIZE];
char ans[SIZE];



void initMatrix(int array[SIZE][SIZE]){
	
	for(int i=0;i<SIZE;i++)
	{	
		for(int j=0;j<SIZE;j++)
		{
			scanf("%d",&array[i][j]);
		}
	}
	
	
}

void initVisited(int *p){
	for(int i=0;i<SIZE;i++){
		p[i]=0;//All cities are not visited at first so they are inititialized to 0
	}
}

void initPrevious(int *p,int src){
	for(int i=0;i<SIZE;i++){
		if(i==src)
			p[i]=-1; //-1 is stored for src
		else
			p[i]=0;//All other ones are initally zero
	}
}

void initDistance(int *p, int source){
	for(int i = 0;i<SIZE;i++){
		if (i==source)
			p[i] = 0;  //Except the source city init them to max so source city is picked first
		else
			p[i] = MAX;
	}
}

void printMatrix(int *array){
	
	for(int j=0;j<SIZE;j++){
		for(int i=0;i<SIZE;i++){
			if((j*SIZE+i)%10==0)
			printf("\n");
		printf("%d ",array[j*SIZE+i]);
		}
		
	}

	
}

void printMatrix1D(int *array){
	
	for(int j=0;j<SIZE;j++){
		printf("%d\n",array[j]);

	}
}

int pickMin(int *dist, int *vstd){
	
	int min = MAX;
	int index = 0;
	
	for(int i=0;i<SIZE;i++){
		if(vstd[i]==0 && dist[i]<min){
			index = i;
			min = dist[i];
		}
	}
	return index;
}

void convert2Dto1D(int array[SIZE][SIZE], int oneD[SIZE*SIZE])
{

	for(int i=0;i<SIZE;i++)
	{
		for(int j=0;j<SIZE;j++)
		{
			oneD[i*SIZE+j] = array[i][j];
		}
	}

}


int *functionFindMin(int *array,int row,int cols,char src,char dest){
	
	for(int i=0;i<row-1;i++){	
		int currentMin = pickMin(distanceList,isVisited);//picked row
		isVisited[currentMin]=1;
		for(int j=0;j<cols;j++){	
			if(array[currentMin*row+j]>0 && isVisited[j]==0 && distanceList[currentMin]!=MAX &&(distanceList[currentMin]+array[currentMin*row+j] < distanceList[j]))
			{
				distanceList[j]=distanceList[currentMin]+array[currentMin*row+j];
				previous[j] = currentMin;
			}	
		}
	}
	int e = dest-'A';
	int counter = 0;
	do{
		ans[counter] = e +'A';
		e = previous[e];
		counter++;
	}while(previous[e]!=-1);
	ans[counter]=src;
}

int lenghtof(char array[]){
	int length = 0;
	
	for (int i=0;array[i]!='\0';i++)
		length++;
	
	return length;
}
void reverse(char ar[]){
	int end = lenghtof(ar)-1;
	int i=0;
	char c;
	for(i;i<lenghtof(ar)/2;i++){
		c = ar[i];
		ar[i]=ar[end];
		ar[end]=c;
		end--;
	}
}
int main(){
	

	int array[SIZE][SIZE];
	initMatrix(array);
	int array1D[SIZE*SIZE];
	convert2Dto1D(array,array1D);
	char src, dest;
	scanf(" %c %c",&src,&dest);	
	initVisited(isVisited);
	initPrevious(previous,src-'A');
	initDistance(distanceList,src-'A');
	functionFindMin(array1D,SIZE,SIZE,src,dest);
	reverse(ans);
	for(int i=0;ans[i]!='\0';i++){
		printf("%c",ans[i]);
		if(ans[i+1]!='\0')
			printf("-");
	}
	printf(" %d\n",distanceList[dest-'A']);

	
	return 0;
}
