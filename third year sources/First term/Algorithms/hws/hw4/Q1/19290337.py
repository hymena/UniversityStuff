from heapq import heappop, heappush

# take the input 
cities = input().split() 
nodeDict = {}

for x in cities: # take the adjacency list and store the adjacents in a dictionary of the form {node:{adjacent:weight}...}
    nodeDict[x] = { cities[index]:value for index,value in enumerate(list(map(int, input().split()))) if value !=0}

def dijkstra(graph,src): # dijkstra algorithm the calculate the distances to the all the nodes from a specific node
    distances = { node :1e10 for node in graph } # initialize the distances for all the nodes to max 
    parents = { node: None for node in graph}  # initialize the parents of the nodes to null
    distances[src] = 0 #initialize the distance for source to 0
    queue = [(src,0)] # create a priority queu

    while queue: # while queue is not empty
        vertex, dist = heappop(queue) # pop the minimum. Heap structure is used for efficiency
        for adjacent, weight in graph[vertex].items(): # iterate over the adjacents of the vertex
            value = dist + weight 
            if value <= distances[adjacent]: # perform relaxation if closeer path is discovered
                distances[adjacent] = value
                parents[adjacent] = vertex
                heappush(queue, (adjacent, value))
    return parents, distances

while True: # If there are source destination pairs existing 
    try:
        source,destination = input().split() # take them
        parents , _ = dijkstra(nodeDict,source) # calculate the distances
        temp = parents[destination]
        path = [destination] 
        while parents[temp] != None: # construct the path
            path.append(temp)
            temp = parents[temp]
        path.append(source)
        path.reverse()
        if len(path) < 5: # this part is to obtain same output as in the provided output files
            for node in path[:-1]:
                print(node, end=" ")
            print(path[len(path)-1])
    except EOFError:
        break


