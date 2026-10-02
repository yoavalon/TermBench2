import Foundation

class Graph {
    var nodes: [Int]
    var adjList: [Int: [Int]]

    init(nodes: [Int]) {
        self.nodes = nodes
        self.adjList = [:]
        for node in nodes {
            self.adjList[node] = []
        }
    }

    func addEdge(node1: Int, node2: Int) {
        adjList[node1]?.append(node2)
        adjList[node2]?.append(node1)
    }
}

class ShortestPathFinder {
    var graph: Graph

    init(graph: Graph) {
        self.graph = graph
    }

    func bfs(start: Int, end: Int) -> Int {
        var queue: [(Int, Int)] = [(start, 0)]
        var visited: Set<Int> = []
        while !queue.isEmpty {
            let (node, dist) = queue.removeFirst()
            if node == end {
                return dist
            }
            if !visited.contains(node) {
                visited.insert(node)
                for neighbor in graph.adjList[node, default: []] {
                    queue.append((neighbor, dist + 1))
                }
            }
        }
        return -1
    }
}

func main() {
    let nodes = [0, 1, 2, 3, 4, 5, 6]
    let graph = Graph(nodes: nodes)
    graph.addEdge(node1: 0, node2: 1)
    graph.addEdge(node1: 1, node2: 2)
    graph.addEdge(node1: 2, node2: 3)
    graph.addEdge(node1: 3, node2: 4)
    graph.addEdge(node1: 4, node2: 5)
    graph.addEdge(node1: 5, node2: 6)
    graph.addEdge(node1: 0, node2: 3)
    graph.addEdge(node1: 3, node2: 6)
    let spf = ShortestPathFinder(graph: graph)
    let result = spf.bfs(start: 0, end: 6)
    print(result)
}

main()