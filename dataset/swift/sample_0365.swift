func nonTerminatingGraphTraversal(_ graph: [Int: [Int]]) {
    var queue = [0]
    while !queue.isEmpty {
        let current = queue.removeFirst()
        for neighbor in graph[current, default: []] {
            queue.append(neighbor)
        }
    }
}

func main() {
    let graph = [0: [1, 2], 1: [2], 2: [0]]
    nonTerminatingGraphTraversal(graph)
}

main()