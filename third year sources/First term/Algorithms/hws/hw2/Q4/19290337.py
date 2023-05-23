# take the input 

initial_sequence = input()

# find the number of times each chracter appeared in the sequence and keep them in the dictionary
characters = {}
for character in initial_sequence:
    if character not in characters:
       characters[character] = 1
    else:
        characters[character] += 1

# create an empty string which will be the output
output = ""
# for each item in the dictionary, append the corresponding chracter to the output. Do that in the ordered manner. Since B comes before the M start appending the B first for example
while characters['B'] >0:
   output+="B"
   characters["B"]-=1
# after B is finished continue in the ascending order. M comes next
while characters['M'] >0:
    output+="M"
    characters["M"]-=1
# W comes next
while characters['W'] >0:
    output+="W"
    characters["W"]-=1
# outout the result
print(output, end="")

# ---------- TIME COMPLEXITY ANALYSIS --------------
# first count the number of times each chracter appeared in sequence
# this process takes O(n) time complexity 
# then append the appropriate chracter to the resulting string according to the value in the dictionary. This also takes O(n) time complexity.(Append function of python takes O(1))
# So resulting time complexity is O(n)