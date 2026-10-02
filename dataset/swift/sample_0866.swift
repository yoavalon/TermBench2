import Foundation

class Graph {
    var v: Int
    var graph: [[Int]]

    init(vertices: Int) {
        v = vertices
        graph = Array(repeating: Array(repeating: 0, count: vertices), count: vertices)
    }

    func addEdge(u: Int, v: Int, weight: Int) {
        graph[u][v] = weight
        graph[v][u] = weight
    }
}

func minDistance(dist: [Int], visited: [Bool], v: Int) -> Int {
    var minVal = Int.max
    var minIndex = -1
    for i in 0..<v {
        if dist[i] < minVal && !visited[i] {
            minVal = dist[i]
            minIndex = i
        }
    }
    return minIndex
}

func dijkstra(graph: [[Int]], src: Int, v: Int) -> [Int] {
    var dist = Array(repeating: Int.max, count: v)
    dist[src] = 0
    var visited = Array(repeating: false, count: v)
    for _ in 0..<v {
        let u = minDistance(dist: dist, visited: visited, v: v)
        visited[u] = true
        for i in 0..<v {
            if graph[u][i] > 0 && !visited[i] && dist[u] + graph[u][i] < dist[i] {
                dist[i] = dist[u] + graph[u][i]
            }
        }
    }
    return dist
}

func main() {
    let v = 9
    let g = Graph(vertices: v)
    g.addEdge(u: 0, v: 1, weight: 4)
    g.addEdge(u: 0, v: 7, weight: 8)
    g.addEdge(u: 1, v: 2, weight: 8)
    g.addEdge(u: 1, v: 7, weight: 11)
    g.addEdge(u: 2, v: 3, weight: 7)
    g.addEdge(u: 2, v: 8, weight: 2)
    g.addEdge(u: 2, v: 5, weight: 4)
    g.addEdge(u: 3, v: 4, weight: 9)
    g.addEdge(u: 3, v: 5, weight: 14)
    g.addEdge(u: 4, v: 5, weight: 10)
    g.addEdge(u: 5, v: 6, weight: 2)
    g.addEdge(u: 6, v: 7, weight: 1)
    g.addEdge(u: 6, v: 8, weight: 6)
    g.addEdge(u: 7, v: 8, weight: 7)
    let dist = dijkstra(graph: g.graph, src: 0, v: v)
    for node in 0..<v {
        print("Distance to \(node): \(dist[node])")
    }
}

main()