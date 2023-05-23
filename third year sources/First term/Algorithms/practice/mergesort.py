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
