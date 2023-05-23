def binarySearch(x,s,e,v):
	if(s==e):
		return -1
	mid =int((s+e)/2)
	if(v>x[mid]):
		return binarySearch(x,mid+1,e,v)
	elif(v<x[mid]):
		return binarySearch(x,s,mid-1,v)

	return mid


n = int(input("number of numbers\n"))
numbers= []
for i in range(n):
	numbers.append(int(input("give me a number: \n")))


print(binarySearch(numbers,0,len(numbers)-1,int(input("nmber\n"))))

