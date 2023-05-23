# This code tries to detect cycles in a given graph
# God forgive me for what I am about to do


# first of all, the input is nxn adjacency matrix for directed graph

adjacency_matrix = [
    [0,1,1,0,0,0,0,0],
    [0,0,1,1,0,0,0,0],
    [0,0,0,1,0,0,1,0],
    [0,0,0,0,1,0,0,0],
    [0,0,0,0,0,1,0,0],
    [0,0,0,0,0,0,1,0],
    [0,0,0,0,1,0,0,1],
    [0,0,1,0,1,0,0,0],
]

class Node():
    def __init__(self, adjacency_matrix_row,i):
        self.adjacency_list = [i for i in range(len(adjacency_matrix_row)-1) if adjacency_matrix_row[i]==1]
        self.color = "white" # color to indicate if a node is visited or not or finished 
        self.parent = 0 # parent 

# Initialization part of the nodes
nodes = []
i=0
for i  in range(len(adjacency_matrix)):
    node = Node(adjacency_matrix[i],i)
    print(i,node.adjacency_list,node.color,node.parent)
    nodes.append(node)
    i+=1


nodes[0].node_name = "a"
nodes[1].node_name = "b"
nodes[2].node_name = "c"
nodes[3].node_name = "d"
nodes[4].node_name = "e"
nodes[5].node_name = "f"
nodes[6].node_name = "g"
nodes[7].node_name = "s"

def DFS():
    for node in nodes:
        if node.color == "white":
            DFS_VISIT(node)  

def DFS_VISIT(node):
    node.color = "gray"
    print(node.node_name)
    for adjacent in node.adjacency_list:
        if nodes[adjacent].color == "gray":
            print(f'Cycle found to {nodes[adjacent].node_name}')
            pass
        else:
            DFS_VISIT(nodes[adjacent])
    node.color = "black"


DFS()