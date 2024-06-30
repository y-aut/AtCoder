import random as rd

def get_tree_edges(n):
    edges = [[] for _ in range(n)]
    for i in range(1, n):
        to = rd.randint(0, i - 1)
        edges[i].append(to)
        edges[to].append(i)
    return edges

def print_edges(edges, bidir: bool):
    for i in range(len(edges)):
        for j in edges[i]:
            if not bidir or i <= j:
                print(i + 1, j + 1)
