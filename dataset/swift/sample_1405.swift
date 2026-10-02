import Foundation

class Graph {
    var n: Int
    var edges: [[Int]]

    init(n: Int) {
        self.n = n
        self.edges = Array(repeating: [Int](), count: n)
    }

    func addEdge(u: Int, v: Int) {
        edges[u].append(v)
        edges[v].append(u)
    }

    func getNeighbors(v: Int) -> [Int] {
        return edges[v]
    }
}

func bfs(graph: Graph, start: Int, end: Int) -> Int {
    var visited = Array(repeating: false, count: graph.n)
    var queue: [(Int, Int)] = [(start, 0)]
    visited[start] = true
    while !queue.isEmpty {
        let (current, distance) = queue.removeFirst()
        if current == end {
            return distance
        }
        for neighbor in graph.getNeighbors(v: current) {
            if !visited[neighbor] {
                visited[neighbor] = true
                queue.append((neighbor, distance + 1))
            }
        }
    }
    return -1
}

func findShortestPath(graph: Graph, start: Int, end: Int) -> Int {
    return bfs(graph: graph, start: start, end: end)
}

func main() {
    let n = 10
    let graph = Graph(n: n)
    graph.addEdge(u: 0, v: 1)
    graph.addEdge(u: 1, v: 2)
    graph.addEdge(u: 2, v: 3)
    graph.addEdge(u: 3, v: 4)
    graph.addEdge(u: 4, v: 5)
    graph.addEdge(u: 5, v: 6)
    graph.addEdge(u: 6, v: 7)
    graph.addEdge(u: 7, v: 8)
    graph.addEdge(u: 8, v: 9)
    graph.addEdge(u: 9, v: 0)
    let start = 0
    let end = 5
    let pathLength = findShortestPath(graph: graph, start: start, end: end)
    print(pathLength)
}

main()