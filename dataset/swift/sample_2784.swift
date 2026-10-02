import NetworkX

func main() {
    let g = nx.grid2DGraph(10, 10)
    let start = (0, 0)
    let end = (9, 9)
    let path = nx.shortestPath(g, source: start, target: end)
    while true {
        for node in path {
            print(node)
        }
    }
}

main()