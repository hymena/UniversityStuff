# Taking the input
# Take the number of nodes in the graph
number_of_nodes = int(input())
# Create a dictionary to store the adjacencies of each node in the graph
# For example graph[0] will store the all neighbours of the node 0
graph ={}
for i in range(number_of_nodes):
    adjacency_for_i = list(map(int,input().split())) # take each line as a adjacency list for a given node, map it to the int and store as a list
    graph[i] = [j for j in range(len(adjacency_for_i)) if adjacency_for_i[j]!=0] # iterate over the list and add the neighbours to the graph

# Graph is traversed by DFS algorithm
parent = {0:None} # parent dictionary stores the parents of nodes in the graph. Also give info the info that if a node is visited before or not.
# Since the 0 is the starting node it's parent is initialized in the dictionary as None

def DFS(graph):# DFS function 
    parent = {}
    for source in graph: # for each node in the graph, it executes the DFS_visit function if the node has not visited yet
        if source not in parent:
            parent[source] = None
            DFS_visit(graph, source)

def DFS_visit(graph,s):#DFS_visit function takes a node s
    for vertex in graph[s]:#checks the nodes adjacencies 
        if vertex not in parent:# if they are not visited before, if they are not in the parent dictionary, they will be visited
            parent[vertex] = s # parent is associated 
            DFS_visit(graph,vertex) # then DFS_visit is called again to go deep into the graph. Current vertex's childs are visited if there any 
        else: # If the vertex is visited before and appeared again in the neighbours of any node than it means cycle is exists
            count = 2 # variable to count length of the cycle. It is initialized to 2 since the distance between vertex and temp (s's parent) is 2 edges
            temp = parent[s] 
            while(temp!= None): # Untill reaching the vertex again, go backward and count the edges 
                if temp==vertex:
                    if count>1 and count%2 != 0: # If the cycle's lenght is odd 
                        print("true",end="")#then output it and terminate the program since 1 odd lenght cycle is enough. No need to searh the rest of the graph
                        exit(0)
                    else:
                        break
                count += 1
                temp = parent[temp]            
            

DFS(graph)#If the program doesn't terminated then there is no odd lenght cycle 
print("false",end="")# Output the result

# --------- TIME COMPLEXITY ANALYSIS ----------
# Depth first search is used in the program. For each node in the graph each edge is passed once 
# DFS's time complexity is O(n+m)
# If there is cycle in the graph, program looped backward to find the starting node of cycle in order to find the length of the cycle 