# input is series of profit for the length of the rod
# example input [1,5,8,9,10]. Indices indicates the length of the rod. First index means that rod's lenght is 1 and its value 1
# Second index means that rod's length is 2 and its value 5
# Take the input 

values = list(map(int,input("give the input: ").split()))

M = {0:0}

for i in range(len(values)):
    M[i+1] = -10e10
    for j in range(i+1):
        temp = M[i-j] + values[j]
        if temp > M[i+1]:
            M[i+1] = temp

print(M)

