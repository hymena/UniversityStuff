

def fnc(x):

	if(x == ""):
		return ""

	return fnc(x[1:]) + x[0]


y = input("give input")

print(fnc(y))
