# first take the input 
# created a simple Software class that keep the ids and prices 
class Software:
    def __init__(self,  s_id, price) -> None:
        self.s_id = s_id 
        self.price = price

# take the inputs and store them in the array
softwares = []
while True:
    try:
        s_id, price = map(int,input().split())
        softwares.append(Software(s_id,price))
    except EOFError:
        break
# To minimize the maximum cost, we need to pick the most expensive license each month.  If we do not pick it, its price will double in the next
# month and the cost will be much more higher than if we had picked it.
# So we need to sort the licenses according to the their price. Then, each month purchase the most expensive license among the remaining ones
# To sort the array merge sort is used 
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
        if left[l].price >= right[r].price: #If left one is greater than add that one
            sorted_array.append(left[l]) # and increase the left counter
            l+=1
        else:
            sorted_array.append(right[r]) # do the same thing when right one is greater
            r+=1
      
    sorted_array += left[l:] # finally add if there any remaining elements 
    sorted_array += right[r:]

    return sorted_array


sorted_array = merge_sort(softwares)

for i in range(len(sorted_array)-1):
    print(sorted_array[i].s_id,end=" ")
print(sorted_array[-1].s_id)

# for time complexity, sorting takes O(nlogn) times where n is the input size.
# for greedy choice property analysis, let's say there is a solution A which is created by another algorithm
# and the resulting order for this algorithm 1,2,3,4. Since this solution is created by another approach than our approach
# one possible case for prices is  p2>p1>p3>p4. Our greedy choice property claims that when most expensive one obtained first 
# then the profit increases. When we convert the solution A into the solution satisfies our greedy choice property we observe that
# profit is increases since p2 is greater than p1 and when p2 is obtained late than p1 total cost is increasing 