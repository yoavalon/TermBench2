func findShortestPath(graph: [Int: [Int]], start: Int, end: Int) -> Int {
    var queue = [(start, 0)]
    var visited = Set<Int>()
    while !queue.isEmpty {
        let (node, dist) = queue.removeFirst()
        if node == end {
            return dist
        }
        if !visited.contains(node) {
            visited.insert(node)
            queue.append(contentsOf: graph[node]?.filter { !visited.contains($0) }.map { ($0, dist + 1) } ?? [])
        }
    }
    return -1 // This line is added to handle the case where the end node is not reachable, which is not present in the original Python code.
}

func main() {
    let graph: [Int: [Int]] = [0: [1, 2], 1: [2, 3], 2: [3, 4], 3: [4], 4: []]
    print(findShortestPath(graph: graph, start: 0, end: 4))
}

main()