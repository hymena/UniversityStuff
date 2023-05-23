# take the input 
class Node: # structure to represent nodes and their adjacent list
    def __init__(self, id, adjacentList) -> None:
        self.id = id
        self.adjacentList = adjacentList

nodeList = [] # list to store  nodes
# each node in the list stores the adjacent nodes as a list
i = 0
while True:
    try:
        temp = list(map(int, input().split()))
        temp = [ node for node in range(len(temp))  if temp[node] != 0]
        node = Node(i,temp)
        nodeList.append(node)
        i+=1
    except EOFError:
        break

# Since all the weights are equal, any spanning tree - any tree that connect all the vertices- can be considered as the minimum
# spanning tree. That means there are mor than one solution. For one of the solutions, I used Breadth first search to scan the graph.
#  When the node discovered first time it is added to the spanning tree with its childs
 

spanningTree = {} # create an empty dictionary that represents the nodes in spanning tree.
# in the spanningTree dictionary, keys represents the nodes in the tree and the values for keys represents the childs of nodes
# for example the pair in spanningTree ={0:[1,7]} means that the node 0 in the tree has 2 childs and these are 1 and 7
queue = [nodeList[0].id] # create a queue and initialize it with the first node in the node list 
visited = [] # list to keep track of the nodes that are visited.

# Implementation of BFS
while queue: # while queue is not empty 
    node = queue[0] # dequeue the first element in the queue
    queue = queue[1:] # update the queue
    if nodeList[node].id not in spanningTree: # if the dequeued node is not in the spanning tree yet
        visited.append(nodeList[node].id) # mark the node as visited
        childs = [] # create a list to store the childs of node 
        for adjacent in  nodeList[node].adjacentList: # then add the adjacent nodes of the current element to the queue if they are not in the queue already
            if adjacent not in queue and adjacent not in visited:                
                queue.append(adjacent) # if the adjacent of the node is not in the queue, then add it to the queue
                childs.append(adjacent) # if the adjacent of the node corresponds to possible child of the node in the tree, if the adjacent is not visited before, then it means we can add it to the childs of node in the tree
        spanningTree[nodeList[node].id] = childs # add the node to the spanning tree with the childs as value 

# So after the iterations, the spanningTree contains the nodes of the minimum spanning tree in the form of adjacancy list

for i in spanningTree:
    print(i, end=" ")
# for the time complexity analaysis, the time complexity for the BFS with the adjacency list is O(V+E)
# In each iteration of the while loop, we visit a new vertex and add its neighbors to the queue.
# Since each vertex is added to the queue at most once, the while loop will run V times. 
# Additionally, the loop body has O(E) time complexity because we iterate over all the neighbors of the current vertex. 
# Thus, the overall time complexity is O(V+E).
