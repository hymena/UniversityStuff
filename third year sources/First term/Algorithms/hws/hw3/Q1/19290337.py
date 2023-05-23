# To find the mininum number of attempts that guaranties the finding pivot floor (floor that egg starts breaking when droped)
# we should try each floor. For example we have n floors and m balls. We should find the number of attempts that when we start 
# from any floor. Let's say we start droping eggs from floor ni and it takes xi total droping. Then we check the floor nj and it
# takes xj attempts. After calculating number of attempts for each floor then we take the minimum of it.
# To calculate number of attempts for each floor we simulate for each floor. And there are 2 possible outcomes for each simulation
# 1st one the egg breaks. When egg breaks then it means that pivot floor is in the below part of building. And we continue calculation  
# on that part of the building with the one less eggs. In the 2nd outcome the egg does not break so the pivot floor is on the upper side
# of the building. We continue investigation with the remaining number of floors and with the same number of eggs
# when there is only one egg remains it means that we need to try at least the number of floors remaining to test. So this is our first base case
# Also when there are only one floor remaining to test it only takes 1 try and if there are no floors to test it takes 0 try. This is the second base case.

#take input
floors, balls = map(int,input().split())
# Since each function call creates two more function call the running time of this method is exponential unless memoization is used.
# So for memoization 2d array is used 
# init an empty array
memoization = [ [1000]*(floors+1) for i in range(balls+1)]
# set the base cases 
# if there is only one floor it always takes one attempts
for i in range(balls+1):
    memoization[i][0] = 0
    memoization[i][1] = 1

# if there is only one ball left it always takes number of floors attempts
for i in range(floors+1):
    memoization[1][i] = i
    memoization[0][i] = 0

# define the recursive function 
def drop(remaining_balls,remaining_floors):
    # construct base cases
    if( remaining_floors == 0 or remaining_balls == 1 or memoization[remaining_balls][remaining_floors] != 1000): # if we hit the base case or the case already calculated then returned it
        return memoization[remaining_balls][remaining_floors]

    # If the case have not been calculated yet, simulate for all floors from 1 to current floor and take the minimum of the number of attempts
    for floor in range(1, remaining_floors+1):
        res = max(drop(remaining_balls,remaining_floors-floor),drop(remaining_balls-1,floor-1)) # calculate worst case scenario for the current floor
        if res < memoization[remaining_balls][remaining_floors]: #If the calculated value is less than current min than update the current min
            memoization[remaining_balls][remaining_floors] = res  
        
    memoization[remaining_balls][remaining_floors] += 1 # for each function call we make one try so add one 
    return memoization[remaining_balls][remaining_floors] 
    
print(drop(balls,floors))
