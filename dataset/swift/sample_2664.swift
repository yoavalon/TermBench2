swift
import Foundation

class Graph {
    var nodes: Int
    var edges: [[Int]]

    init(n: Int) {
        self.nodes = n
        self.edges = Array(repeating: [Int](), count: n)
    }

    func connect(u: Int, v: Int) {
        edges[u].append(v)
        edges[v].append(u)
    }

    func findShortestPaths(start: Int, end: Int) -> Int {
        var queue = [(start, 0)]
        var visited = Array(repeating: false, count: nodes)
        visited[start] = true
        while !queue.isEmpty {
            let (current, distance) = queue.removeFirst()
            if current == end {
                return distance
            }
            for neighbor in edges[current] {
                if !visited[neighbor] {
                    visited[neighbor] = true
                    queue.append((neighbor, distance + 1))
                }
            }
        }
        return -1
    }
}

func generateSequence(n: Int) -> Graph {
    let graph = Graph(n: n)
    for i in 0..<n {
        graph.connect(u: i, v: (i + 1) % n)
    }
    return graph
}

func main() {
    let n = 10
    let graph = generateSequence(n: n)
    let start = 0
    let end = 5
    let result = graph.findShortestPaths(start: start, end: end)
    print(result)
}

main()