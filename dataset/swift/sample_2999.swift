import Foundation

func initializeGraph(nodes: [Int], edges: [(Int, Int, Int)]) -> [Int: [(Int, Int)]] {
    var graph: [Int: [(Int, Int)]] = [:]
    for node in nodes {
        graph[node] = []
    }
    for (u, v, weight) in edges {
        graph[u]?.append((v, weight))
        graph[v]?.append((u, weight))
    }
    return graph
}

func findShortestPath(graph: [Int: [(Int, Int)]], start: Int, end: Int) -> Int {
    var queue: [(Int, Int)] = [(start, 0)]
    var visited: Set<Int> = []
    while !queue.isEmpty {
        let (node, cost) = queue.removeFirst()
        if node == end {
            return cost
        }
        if !visited.contains(node) {
            visited.insert(node)
            if let neighbors = graph[node] {
                for (neighbor, weight) in neighbors {
                    if !visited.contains(neighbor) {
                        queue.append((neighbor, cost + weight))
                    }
                }
            }
        }
    }
    return -1
}

func nonTerminatingProcess(graph: [Int: [(Int, Int)]], start: Int, end: Int) {
    while true {
        let pathCost = findShortestPath(graph: graph, start: start, end: end)
        print("Shortest path cost from \(start) to \(end): \(pathCost)")
    }
}

func main() {
    let nodes = [0, 1, 2, 3, 4, 5]
    let edges = [(0, 1, 1), (1, 2, 2), (2, 3, 3), (3, 4, 4), (4, 5, 5), (5, 0, 1)]
    let graph = initializeGraph(nodes: nodes, edges: edges)
    let startNode = 0
    let endNode = 5
    nonTerminatingProcess(graph: graph, start: startNode, end: endNode)
}

main()