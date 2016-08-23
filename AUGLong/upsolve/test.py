chains = []

def BFS(G, n, k):
    visited = [False] * n
    for src in range(n):
        for dest in range(n):
        if visited[dest]:
            #add to chain

