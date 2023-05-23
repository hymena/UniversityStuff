#include<stdio.h>
#include<stdbool.h>
#define SIZE 15


//Global variables
bool toRight = false;
bool toDown = false;
bool toLeft = false;
bool toUp = false;                                       //Variables that keeps the info about possible ways
bool diagRU = false;
bool diagRD = false;
bool diagLU = false;
bool diagLD = false;


int lenghtof(char array[]){                             //Function the find the lenght of the query array
	int length = 0;
	
	for (int i=0;array[i]!='\0';i++)
		length++;
	
	return length;
}

void takeInput(char ar[SIZE][SIZE]){                    //Taking the given input into a 2d array
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            scanf(" %c",&ar[i][j]);
        }
    }
}

void printArray(char ar[SIZE][SIZE]){
    for(int i=0;i<SIZE;i++){           
        for(int j=0;j<SIZE;j++){                        //Function to print 2D array
            printf("%c", ar[i][j]);
        }
        printf("\n");
    }
}

void checkPossibleWays(int row, int col, int len){      //pass here i+1 and j+1
    if(col >= len)                                      //Function to check possible ways
        toLeft = true;
    else
        toLeft = false;
    if((SIZE - col ) >= len-1)
        toRight = true;
    else
        toRight = false;
    if(row >= len)
        toUp = true;
    else
        toUp = false;
    if((SIZE - row ) >= len-1)
        toDown = true;
    else
        toDown = false;
    if (toRight && toUp)
        diagRU = true;
    else
        diagRU = false;
    if(toRight && toDown)
        diagRD = true;
    else
        diagRD = false;
    if(toLeft && toUp)
        diagLU = true;
    else 
        diagLU = false;
    if(toLeft && toDown)
        diagLD = true;
    else
        diagLD = false;    
}

int findRight(char input[SIZE][SIZE],char ans[SIZE][SIZE], char query[], int i, int j){

    for(int k = 1;k<lenghtof(query);k++){
        if(input[i][j+k] != query[k])                   //Function for checking word from right to left
            return 0;       
    }
    for(int k = 0;k<lenghtof(query);k++)
        ans[i][j+k]=input[i][j+k];      
    return 1;
}

int findDown(char input[SIZE][SIZE],char ans[SIZE][SIZE], char query[], int i, int j){
    for(int k = 1;k<lenghtof(query);k++){
        if(input[i+k][j] != query[k])                  //Function for checking word from up to down
            return 0;       
    }
    for(int k = 0;k<lenghtof(query);k++)
        ans[i+k][j]=input[i+k][j]; 
    return 1;
}

int findLeft(char input[SIZE][SIZE],char ans[SIZE][SIZE], char query[], int i, int j){
    for(int k = 1;k<lenghtof(query);k++){
        if(input[i][j-k] != query[k])                   //Function for checking word from left to right
            return 0;       
    }
    for(int k = 0;k<lenghtof(query);k++)
        ans[i][j-k]=input[i][j-k];
    return 1;
}

int findUp(char input[SIZE][SIZE],char ans[SIZE][SIZE], char query[], int i, int j){
    for(int k = 1;k<lenghtof(query);k++){
        if(input[i-k][j] != query[k])                  //Function for checking word from down to up
            return 0;       
    }
    for(int k = 0;k<lenghtof(query);k++)
        ans[i-k][j]=input[i-k][j];
    return 1;
}

int findRightUp(char input[SIZE][SIZE],char ans[SIZE][SIZE], char query[], int i, int j){
    for(int k = 1;k<lenghtof(query);k++){
        if(input[i-k][j+k] != query[k])                  //Function for checking word diagonally rigth up
            return 0;       
    }
    for(int k = 0;k<lenghtof(query);k++)
        ans[i-k][j+k]=input[i-k][j+k];
    return 1;
}
int findRightDown(char input[SIZE][SIZE],char ans[SIZE][SIZE], char query[], int i, int j){
    for(int k = 1;k<lenghtof(query);k++){
        if(input[i+k][j+k] != query[k])                  //Function for checking word diagonally rigth down
            return 0;       
    }
    for(int k = 0;k<lenghtof(query);k++)
        ans[i+k][j+k]=input[i+k][j+k];
    return 1;
}
int findLeftDown(char input[SIZE][SIZE],char ans[SIZE][SIZE], char query[], int i, int j){
    for(int k = 1;k<lenghtof(query);k++){
        if(input[i+k][j-k] != query[k])                  //Function for checking word diagonally left down
            return 0;       
    }
    for(int k = 0;k<lenghtof(query);k++)
        ans[i+k][j-k]=input[i+k][j-k];
    return 1;
}

int findLeftUp(char input[SIZE][SIZE],char ans[SIZE][SIZE], char query[], int i, int j){
    for(int k = 1;k<lenghtof(query);k++){
        if(input[i-k][j-k] != query[k])                  //Function for checking word diagonally left up
            return 0;       
    }
    for(int k = 0;k<lenghtof(query);k++)
        ans[i-k][j-k]=input[i-k][j-k];
    return 1;
}

void initAns(char ar[SIZE][SIZE]){
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++){
            ar[i][j]='*';
        }
    }
}



int main(void){

char input[SIZE][SIZE];
char queryString[SIZE];
takeInput(input);
scanf("%s",queryString);
int lenOfQuery = lenghtof(queryString);
int found = 0;
char ans[SIZE][SIZE];
initAns(ans);

for(int i=0;i<SIZE;i++){           
        for(int j=0;j<SIZE;j++){
            checkPossibleWays(i+1,j+1,lenOfQuery);

            if((input[i][j] == queryString[0]) && toRight)
                found = findRight(input,ans, queryString, i, j);
            if(found)
                break;
            if((input[i][j] == queryString[0]) && toDown)
                found = findDown(input,ans, queryString, i, j);
            if(found)
                break;
            if((input[i][j] == queryString[0]) && toLeft)
                found = findLeft(input,ans, queryString, i, j);
            if(found)
                break;
            if((input[i][j] == queryString[0]) && toUp)
                found = findUp(input,ans, queryString, i, j);
            if(found)
                break;
            if((input[i][j] == queryString[0]) && diagRU)
                found = findRightUp(input,ans, queryString, i, j);
            if(found)
                break;
            if((input[i][j] == queryString[0]) && diagRD)
                found = findRightDown(input,ans, queryString, i, j);
            if(found)
                break;
            if((input[i][j] == queryString[0]) && diagLD)
                found = findLeftDown(input,ans, queryString, i, j);
            if(found)
                break;
            if((input[i][j] == queryString[0]) && diagLU)
                found = findLeftUp(input,ans, queryString, i, j);
            if(found)
                break;          
        }
        if(found)
         break;
    }

    printArray(ans);
    return 0;
}