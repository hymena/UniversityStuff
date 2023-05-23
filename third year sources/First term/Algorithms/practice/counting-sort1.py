sequence = list(map(int, input("give the sequence: ").split()))

max_of_the_sequence = max(sequence)

counting_list = []
print(sequence)
for i in range(max_of_the_sequence + 1):
    counting_list.append(0)

for i in range(len(sequence)):
    counting_list[sequence[i]] = counting_list[sequence[i]] + 1

print(counting_list)
for i in range(1,len(sequence)-1):
    counting_list[i] = counting_list[i] + counting_list[i-1]

sorted_list = []
for i in range(len(sequence)):
    sorted_list.append(0)
print(counting_list)
for i in range(len(sequence)-1,-1,-1):
    sorted_list[counting_list[sequence[i]]-1] = sequence[i]
    counting_list[sequence[i]] -= 1  
    print(sorted_list)
