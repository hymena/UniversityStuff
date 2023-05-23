sequence = list(map(int, input("give the input: ").split())) #take the input 
length_of_sequnece = len(sequence)

counting_list = []

for i in range(length_of_sequnece):
    counting_list.append(0)

for i in range(length_of_sequnece-1): # count the number of elements that smaller than a particular element
    for j in range(i+1, length_of_sequnece):
        if sequence[i] < sequence[j]:
            counting_list[j] = counting_list[j] + 1
        else:
            counting_list[i] = counting_list[i] + 1

sorted_sequence = []
for i in range(length_of_sequnece): #initialize the resulting index
    sorted_sequence.append(0)
print(counting_list)
for i in range(length_of_sequnece):
    sorted_sequence[counting_list[i]] = sequence[i]

print(sorted_sequence)