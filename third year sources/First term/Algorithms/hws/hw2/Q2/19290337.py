# Taking input 
matrix = []
while(True):
    try:
        matrix.append(list(map(int,input().split())))
    except EOFError:
        break

# Among the group of n people let's say consider two of them person A and person B
# If the person A knows B then there is no chance that A is celebrity
# If the person B knows A then A could be celebrity but B can not be celebrity since B knows someone
# If neither A or B knows each other then they both can be celebrity and this info doesn't give us much we need to compare another
# So first we need a function that returns the info if A knows B 
def does_A_knows_B(A,B):
    return matrix[A][B]

# After that we need a mechanism that select the possible celebrity and discards other each time we investigate if A knows B
# For example if A knows B then B is returned to be investigated again and A is out of problem. With this approach input size is decreased by one each time
# To achive this recursive function is used 
# In each function call function itself is called againg untill reaching the base case which is 0   
def findCelebrity(n):
    if n==0: # base case is 0 since the 0 is the starting index.
        return 0
    possible_celebrity = findCelebrity(n-1) # returned value is stored as possible celebrity 
    if(does_A_knows_B(n,possible_celebrity)): # possible celebrity and current n is investigated
        return possible_celebrity   # if n knows possible celebrity then possible celebrity is returned to the next function in function call stack and investigated with n+1
    else:
        return n #otherwise n is returned to the next function in function call stack since possible celebrity can not be a celebrity anymore. In the next function n and n+1 one is investigated


# example function call stack. Untill reaching the base case each function call itself with the parameter n-1. f(3) is the first called function and f(0) is the top of function call stack 
#   f(0)    returns 0 and popped from stack. since base case
#   f(1)    investiagetes that does person 1 know person 0. If knows person 0 returned. Otherwise person 1 is returned so that person 1 and 2 investigated 
#   f(2)    returned value investigated and appropriate result is returned to the next function call 
#   f(3)
# After result is returned we have a possible celebrity then we need to check if this celebrity candidate really known by every other person in the group and knows no one
possible_celebrity = findCelebrity(len(matrix)-1)
knows_celebrity = 0 # count variable for the number of people knows celebrity candidate. Must be length of the matrix - 1
celebrity_knows = 0 # count variable for the number of people that celebrity candidate knows. Must be 0
for i in range(len(matrix)):
    knows_celebrity += does_A_knows_B(i,possible_celebrity) # check if each one in the group know celebrity
    celebrity_knows += does_A_knows_B(possible_celebrity,i) # check if celebrity candidate knows anyone 

if (knows_celebrity == (len(matrix)-1) and celebrity_knows == 0): # after all check the conditions and print the result
    print(possible_celebrity)
else:
    print(-1)

# ----- TIME COMPLEXITY ANALYSIS -----
# Since the recursive function is called n times time complexity for that part is O(n)
# For checking the celebrity candidate each person is investigated with the candidate. So again n iteration is performed in the loop. O(n)
# Time complexity for this program is O(n)