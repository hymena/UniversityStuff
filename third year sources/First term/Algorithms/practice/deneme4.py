def sum(x):
	if x==0:
		return x
	return sum(x-1) + x


x = int(input("give me a number\n"))

print(sum(x))
