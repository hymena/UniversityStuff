def sum(x,res):
	if(x==0):
		return res
	return sum(x-1,x+res)

x =int( input("give me a number\n"))

print(sum(x,0))
