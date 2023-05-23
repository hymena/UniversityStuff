# first take the input 

items = list(map(int,input().split()))
# To save as much money as possible, the cheaper one in the pair should be as expensive as possible
# So if we pair the most two expensive items in each step, the total profit is maximized
# Sort the items in the ascending order 
# While sorting merge sort is used

# Merge sort  
def merge_sort(array):
    # If array contains less than 2 element return the array
    if len(array) < 2:
        return array
    
    # find the middle point of the array
    mid = len(array)//2
    # Split the array into 2 from the middle
    left = array[:mid]
    right = array[mid:]
    # recursively continue splitting the array 
    left = merge_sort(left)
    right = merge_sort(right)
    # merge two halves
    return merge(left,right)

# merge 
def merge(left,right):
    sorted_array = [] # initialize an empty array
    l = 0 #counter for left array
    r = 0 #counter for right array
    while  l < len(left) and r < len(right): # while not end of any of the arrays
        if left[l] >= right[r]: #If left one is greater than add that one
            sorted_array.append(left[l]) # and increase the left counter
            l+=1
        else:
            sorted_array.append(right[r]) # do the same thing when right one is greater
            r+=1
      
    sorted_array += left[l:] # finally add if there any remaining elements 
    sorted_array += right[r:]

    return sorted_array

sorted_items = merge_sort(items)
#After sorting the items, start pairing the most two expensive remaining item
# The resulting pairing can be shown as following 
i = 0
while i < len(sorted_items):
    print(sorted_items[i],sorted_items[i+1])
    i+=2 

# for running time analysis, it takes O(nlogn) time complexity since merge sort is used
# for greedy choice property analysis, let's say there is a solution A which is created by another algorithm
# and the resulting pairing for this algorithm is (1,2),(3,4),(5,6). Since this solution is created by another approach than our greedy approach
# one possible case for prices is p1>p3>p2>p5>p6. When we convert the solution A into a solution that satisfies our greedy choice property
# we observe that the total cost decreases. Because we paired the two most expensive ones p1 and p3 instead of p1 and p2. So p3 will be
# free and because of the fact that p3 > p2 the total cost paid will be the cheapest.   