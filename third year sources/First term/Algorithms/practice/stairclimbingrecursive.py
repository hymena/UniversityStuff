import time 

start = time.time()
number_of_stairs = int(input("give the number of stairs: "))
memoization_dict = {}
def sc1(n):
    if n<=1:
        return 1
    return sc1(n-1) + sc1(n-2)
        


def sc(n):
    if n<=1:
        return 1
    if(n in memoization_dict):
        return memoization_dict[n]
    else:
        A = sc(n-1) + sc(n-2)
        memoization_dict[n] = A
        return A
print(sc(number_of_stairs))
end = time.time()
print(end-start)