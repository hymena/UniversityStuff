import time


start = time.time()
number_of_stairs = int(input("give the number of stairs: "))
memoization_dict = {}
memoization_dict[1] = 1
memoization_dict[0] = 1

for i in range(2, number_of_stairs + 1):
    memoization_dict[i] = memoization_dict[i-1] + memoization_dict[i-2]
print(memoization_dict[number_of_stairs])
end = time.time()
print(end-start)