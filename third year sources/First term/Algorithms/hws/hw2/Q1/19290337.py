# Task ordering question
class Task(): # Task class to create tasks
    def __init__(self, task_id, deadline, profit) -> None:
        self.id = task_id # task id for each task
        self.deadline = deadline # deadline for each task
        self.profit = profit # profit for each task

# First take the inputs 
tasks = [] # create an empty tasks list
n = int(input()) # number of tasks is taken
for i in range(n):# number of tasks times input line taken
    task_id, deadline, profit = [int(x) for x in input().split()] #each input line parsed into the appropriate variables 
    task = Task(task_id,deadline,profit) # task object is created 
    tasks.append(task)  # each task appended to the list 

# sort the tasks according to their deadlines
for i in range(1,len(tasks) ): # insertion sort method is used 
    temp = tasks[i]
    j = i -1
    while(j>=0 and tasks[j].deadline > temp.deadline):
        tasks[j+1] = tasks[j]
        j -= 1
    tasks[j+1] = temp

# after sorting the tasks in increasing deadline order iterate over the tasks again and choose the one with most profit
time= 1 # time variable. When one task is choosed it is incremented by one. It starts from 1 since first task in the list alraedy added to result
result = [tasks[0]] #resulting tasks order will be assembled in that variable
tasks = tasks[1:]
for task in tasks:
    if time < task.deadline: #If the time is already less than the current task's deadline than add this task to result and increment time
        result.append(task)
        time += 1
    if time == task.deadline: # If the time is equal to the deadline of current task then another task with same deadline must have been added to the result. And that must be last element in the result 
        if result[len(result)-1].profit < task.profit:# Check the last element's profit and if it's profit is less than current task's swap them.
            result[len(result)-1] = task
    

for task in result[0:-1]:
    print(task.id,end=" ")
print(tasks[-1].id,end="")

# ------- TIME COMPLEXITY ANALYSIS -------
# Insertion sort is used for sorting part so time complexity for that part is O(n^2)
# To take the most profit whole array is walked again so that part takes O(n) time
# The time complexity for the program is O(n^2)
    



