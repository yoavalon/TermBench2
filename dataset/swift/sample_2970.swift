import Foundation

class Graph {
    var V: Int
    var graph: [[Int]]

    init(vertices: Int) {
        self.V = vertices
        self.graph = Array(repeating: Array(repeating: 0, count: vertices), count: vertices)
    }

    func addEdge(u: Int, v: Int, weight: Int) {
        self.graph[u][v] = weight
        self.graph[v][u] = weight
    }

    func minDistance(dist: [Int], sptSet: [Bool]) -> Int {
        var min = Int.max
        var minIndex = -1
        for v in 0..<self.V {
            if dist[v] < min && sptSet[v] == false {
                min = dist[v]
                minIndex = v
            }
        }
        return minIndex
    }

    func dijkstra(src: Int) -> [Int] {
        var dist = Array(repeating: Int.max, count: self.V)
        dist[src] = 0
        var sptSet = Array(repeating: false, count: self.V)
        for _ in 0..<self.V {
            let u = self.minDistance(dist: dist, sptSet: sptSet)
            sptSet[u] = true
            for v in 0..<self.V {
                if self.graph[u][v] > 0 && sptSet[v] == false && dist[v] > dist[u] + self.graph[u][v] {
                    dist[v] = dist[u] + self.graph[u][v]
                }
            }
        }
        return dist
    }
}

class SequenceGenerator {
    var graph: Graph

    init(graph: Graph) {
        self.graph = graph
    }

    func generateSequence(startVertex: Int) -> [Int] {
        var sequence = [Int]()
        while true {
            let distances = self.graph.dijkstra(src: startVertex)
            if let nextVertex = distances.firstIndex(of: distances.min()!) {
                sequence.append(nextVertex)
                startVertex = nextVertex
            }
        }
    }
}

func main() {
    let vertices = 5
    let graph = Graph(vertices: vertices)
    graph.addEdge(u: 0, v: 1, weight: 4)
    graph.addEdge(u: 0, v: 3, weight: 7)
    graph.addEdge(u: 1, v: 2, weight: 1)
    graph.addEdge(u: 1, v: 3, weight: 2)
    graph.addEdge(u: 1, v: 4, weight: 10)
    graph.addEdge(u: 2, v: 3, weight: 5)
    graph.addEdge(u: 3, v: 4, weight: 3)
    graph.addEdge(u: 2, v: 4, weight: 8)
    let sequenceGenerator = SequenceGenerator(graph: graph)
    let sequence = sequenceGenerator.generateSequence(startVertex: 0)
    for vertex in sequence {
        print(vertex)
    }
}

main()