# Since the loop tree is constructed from a binary tree by adding one extra 
# edge to the tree, it has n edges if it has n nodes. So the mimimum spanning 
# tree will have n-1 edges at the end. Prim's and Kruskal's algorithms takes 
# O(nlog(n-1)) time to consturct spanning tree. This is because in both prim's 
# and kruskal's algorithms, priority queue is used and it takes logarithmic time
# to manipulate queue. 
# For a more efficient algorithm we can just detect the cycle and extraxt the edge
# cause a cycle. We don't even need to consider weights. With that manner we automatically
# construct the minimum spanning tree. So for detection of the cycle DFS can be used 


# Take the input
class Node: # structure to represent nodes and their adjacent list
    def __init__(self, id, adjacentList) -> None:
        self.id = id
        self.adjacentList = adjacentList
        self.parent = None
        self.color = "white"

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

# DFS implementation 
def DFS(nodeList):
    for node in nodeList:
        if node.color == "white":
            DFS_visit(node)

# DFS visit
def DFS_visit(node):
    print(node.id, end=" ")
    node.color = "gray"
    for adjacent in node.adjacentList:
        if nodeList[adjacent].color == "white": # if not visited before visit it and mark the color as gray
            nodeList[adjacent].parent = node.id
            DFS_visit(nodeList[adjacent])
        elif nodeList[adjacent].color == "gray" and nodeList[adjacent].id != node.parent: # we found the cycle 
            nodeList[node.id].adjacentList.remove(nodeList[adjacent].id) # remove the edge that cause the cycle
            nodeList[adjacent].adjacentList.remove(node.id) # remove it from both direction
    node.color = "black" # after all mark the node as completed

DFS(nodeList)
# the generated output is the DFS search appearences of the vertices in the minimum spanning tree. Since the DFS order 
# can depends on the implementation, it may be different from your output. But the resulting minimum spanning tree is same.
# for the time complexity analaysis, DFS takes O(m+n) times where there are n vertices and m edges. In the worst case 
# DFS has to visit every edge and vertices.
