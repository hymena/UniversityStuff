#include <stdio.h>
#include <stdlib.h>
#define employee_number 6

struct employee //Structure for employees
{
    int number;            //Employee number is stored here
    struct employee *next; // The next employee's address
};

struct costumer //Structre for costumers
{
    int number;            //Costumer number
    int start;             //The process starting time
    int duration;          //The process duraiton
    int waitingTime;       //The time costumer waited in queue
    struct costumer *next; //The address of next costumer
};

struct employee *top = NULL;                  //The address of the top of the employee stack
struct costumer *start = NULL;                //The address of the beginning of costumer queue
int workingOnes[] = {-1, -1, -1, -1, -1, -1}; //the data for the employees if they are working or not and the remaining working time
//If -1 is stored that means corresponding worker is free
int totalWorkedHours[] = {0, 0, 0, 0, 0, 0}; //the data for employees that how much time they worked

void pushToStack(int number) //Function to push element in stack
{
    struct employee *new = (struct employee *)malloc(sizeof(struct employee));
    new->number = number;
    if (top == NULL)
    {
        new->next = NULL;
        top = new;
    }
    else
    {
        new->next = top;
        top = new;
    }
}

void popFromStack() //Funtion to push element from stack
{
    if (top == NULL)
        printf("No element to pop\n");
    else
    {
        struct employee *temp = top;
        top = top->next;
        free(temp);
    }
}

void initStack() //Funtion to initialize employee stack at the beginning
{

    for (int i = 1; i <= employee_number; i++)
    {
        pushToStack(i);
    }
}

void initQueue() //Funtion to initialize costumer queue at the beginning
{

    while (1)
    {
        int costumerNumber;
        scanf("%d", &costumerNumber);
        if (costumerNumber == -1)
            break;
        struct costumer *new = (struct costumer *)malloc(sizeof(struct costumer));
        int startingTime, durationOfWork;
        scanf("%d %d", &startingTime, &durationOfWork);
        new->duration = durationOfWork;
        new->next = NULL;
        new->number = costumerNumber;
        new->start = startingTime;
        new->waitingTime = 0;

        struct costumer *temp = start;

        if (start == NULL)
        {
            start = new;
        }

        else
        {
            while (temp->next != NULL)
                temp = temp->next;

            temp->next = new;
        }
    }
}

int freeEmployeeChecker() //Funtion to chech if there is a free employee or not
{
    int count = 0;
    for (int i = 0; i < employee_number; i++)
    {
        if (workingOnes[i] != -1)
            count += 1;
    }

    if (count == 6) //That means no employee free
        return 0;
    else
        return 1;
}

int main()
{
    int currentTime = 1; //The variable to keep track of time
    initStack();         //Initialize the stack
    initQueue();         //Initializes the queue

    while (start != NULL) //Iterate while the current queue element is not NULL
    {

        if (start->next == NULL)
        {

            for (int i = 0; i < employee_number; i++) //Iterate over employees
            {
                if (workingOnes[i] != -1)                           //If emlployee is not free
                    workingOnes[i] -= (start->start - currentTime); //Reduce the reamining time
                if (workingOnes[i] == 0)                            //If employee just became free push it to the stack
                {
                    pushToStack(i + 1);
                    workingOnes[i] = -1; //And label it as free employeer
                }
            }

            currentTime = start->start; //After we finished with the calculations update currentTime

            if (!freeEmployeeChecker()) //If there is not free employee
            {
                start->start += 1;       //Increase the starting time for costumer by one
                start->waitingTime += 1; //That means costumer waited in queue so increase waitingTime
                continue;                //Skip the next statements because there is no free employee
            }
            
            printf("%d %d %d %d %d\n", start->number, top->number, currentTime, start->duration + currentTime, start->waitingTime); //Print the neccessary data
            workingOnes[top->number - 1] = start->duration;                                                                         //Label the employee as not free
            totalWorkedHours[top->number - 1] += start->duration;                                                                   //Increase the worked hours of employee
            
            popFromStack();
            break;
        }
        if (start->next->next == NULL)
        {
            for (int i = 0; i < employee_number; i++) //Iterate over employees
            {
                if (workingOnes[i] != -1)                           //If emlployee is not free
                    workingOnes[i] -= (start->start - currentTime); //Reduce the reamining time
                if (workingOnes[i] == 0)                            //If employee just became free push it to the stack
                {
                    pushToStack(i + 1);
                    workingOnes[i] = -1; //And label it as free employeer
                }
            }

            currentTime = start->start; //After we finished with the calculations update currentTime

            if (!freeEmployeeChecker()) //If there is not free employee
            {

                start->start += 1;       //Increase the starting time for costumer by one
                start->waitingTime += 1; //That means costumer waited in queue so increase waitingTime
                continue;                //Skip the next statements because there is no free employee
            }

            printf("%d %d %d %d %d\n", start->number, top->number, currentTime, start->duration + currentTime, start->waitingTime); //Print the neccessary data
            workingOnes[top->number - 1] = start->duration;                                                                         //Label the employee as not free
            totalWorkedHours[top->number - 1] += start->duration;                                                                   //Increase the worked hours of employee
            popFromStack();
            start = start->next;
        }
        

        else
        {
            for (int i = 0; i < employee_number; i++) //Iterate over employees
            {
                if (workingOnes[i] != -1)                           //If emlployee is not free
                    workingOnes[i] -= (start->start - currentTime); //Reduce the reamining time
                if (workingOnes[i] == 0)                            //If employee just became free push it to the stack
                {
                    pushToStack(i + 1);
                    workingOnes[i] = -1; //And label it as free employeer
                }
            }

            currentTime = start->start; //After we finished with the calculations update currentTime

            if (!freeEmployeeChecker()) //If there is not free employee
            {
                struct costumer *temp = start;
                while (temp->start == start->next->start)
                {
                    temp->start += 1;       //Increase the starting time for costumer by one
                    temp->waitingTime += 1; //That means costumer waited in queue so increase waitingTime
                    temp = temp->next;
                }
                continue; //Skip the next statements because there is no free employee
            }

            printf("%d %d %d %d %d\n", start->number, top->number, currentTime, start->duration + currentTime, start->waitingTime); //Print the neccessary data
            workingOnes[top->number - 1] = start->duration;                                                                         //Label the employee as not free
            totalWorkedHours[top->number - 1] += start->duration;                                                                   //Increase the worked hours of employee
            popFromStack();                                                                                                         //Pop the employee from stack
            start = start->next;
            //Go next costumer
        }
    }

    printf("\n");
    for (int i = employee_number; i >= 1; i--) //Print the total worked hours for employees
    {
        printf("%d %d\n", i, totalWorkedHours[i - 1]);
    }

    return 0;
}