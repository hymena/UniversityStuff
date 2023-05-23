# first take the input
A = list(map(int,input().split()))
B = list(map(int,input().split()))

# Then initialize an mxn 'jumps' matrix that will store the number of jumps needed to arrive the corresponding leaf
# For example let's say first frog is on the leaf Ai and second frog is on the leaf Bj. The jump[j][i] will store the 
# number of jumps need to occur. Of course, if the distance between two leaf is greater than 100 cms, then corresponding 
# cell of the matrix will store the number infinitive. Because frogs cannot be more than 1 meter apart. 
# So initialize the matrix
jumps = [ [0]*len(A) for i in range(len(B))]
# The number of jumps that is needed to arrive the leaf Ai and leaf Bj is i+j   
# Define a function that returns if the distance between two leaf is less than a meter or not
def distance(Ai,Bj):
    return abs(Ai-Bj) <= 100
# Loop for each leaf position 
for j in range(len(B)):
    for i in range(len(A)):
        if distance(A[i],B[j]): # check if the distance is less than 1 meter
            jumps[j][i] = i+j # assign the number of jumps needed to arrive leaf Ai and leaf Bj
        else:
            jumps[j][i] = 1000 # if the distance is greater than 1 meter than assign a large value it 
# At the end, if the number of jumps are needed to arrive the leaf An and leaf Bm is equal to the m+n, then there exists a satisfying path
print("true",end="") if((len(A)-1 + len(B) -1 ) == jumps[len(B)-1][len(A)-1]) else print("false",end="")
# The time complexity for the code is O(m.n) since we check the distance for every leaf pair
    