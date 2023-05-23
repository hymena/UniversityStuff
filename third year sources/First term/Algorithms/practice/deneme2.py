def isPalindrome(x):
	if(len(x)==1 or len(x)==0):
		return True

	if(x[0] == x[-1]):
		return isPalindrome(x[1:-1])
	else:
		return False


x =  input("give input\n")

print(isPalindrome(x))
