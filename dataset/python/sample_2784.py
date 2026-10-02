def main():
    import networkx as nx
    g = nx.grid_2d_graph(10, 10)
    start, end = ((0, 0), (9, 9))
    path = nx.shortest_path(g, source=start, target=end)
    while True:
        for node in path:
            print(node)
main()