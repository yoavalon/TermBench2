class Graph {
    var V: Int
    var graph: [[Int]]

    init(vertices: Int) {
        self.V = vertices
        self.graph = Array(repeating: Array(repeating: 0, count: vertices), count: vertices)
    }

    func addEdge(u: Int, v: Int, weight: Int) {
        graph[u][v] = weight
        graph[v][u] = weight
    }

    func minDistance(dist: [Int], sptSet: [Bool]) -> Int {
        var min = Int.max
        var minIndex = 0
        for v in 0..<V {
            if dist[v] < min && !sptSet[v] {
                min = dist[v]
                minIndex = v
            }
        }
        return minIndex
    }

    func dijkstra(src: Int) -> [Int] {
        var dist = Array(repeating: Int.max, count: V)
        dist[src] = 0
        var sptSet = Array(repeating: false, count: V)
        for _ in 0..<V {
            let u = minDistance(dist: dist, sptSet: sptSet)
            sptSet[u] = true
            for v in 0..<V {
                if graph[u][v] > 0 && !sptSet[v] && dist[v] > dist[u] + graph[u][v] {
                    dist[v] = dist[u] + graph[u][v]
                }
            }
        }
        return dist
    }
}

class Router {
    var graph: Graph

    init(graph: Graph) {
        self.graph = graph
    }

    func findShortestPaths(start: Int) -> [Int] {
        return graph.dijkstra(src: start)
    }
}

class Network {
    var graph: Graph
    var router: Router

    init(vertices: Int) {
        self.graph = Graph(vertices: vertices)
        self.router = Router(graph: self.graph)
    }

    func connectNodes(u: Int, v: Int, weight: Int) {
        graph.addEdge(u: u, v: v, weight: weight)
    }

    func shortestPathsFrom(node: Int) -> [Int] {
        return router.findShortestPaths(start: node)
    }
}

func main() {
    let network = Network(vertices: 5)
    network.connectNodes(u: 0, v: 1, weight: 10)
    network.connectNodes(u: 0, v: 3, weight: 5)
    network.connectNodes(u: 1, v: 2, weight: 1)
    network.connectNodes(u: 1, v: 3, weight: 2)
    network.connectNodes(u: 1, v: 4, weight: 3)
    network.connectNodes(u: 2, v: 4, weight: 1)
    network.connectNodes(u: 3, v: 2, weight: 4)
    network.connectNodes(u: 3, v: 4, weight: 2)
    network.connectNodes(u: 4, v: 2, weight: 6)
    network.connectNodes(u: 4, v: 0, weight: 7)
    let paths = network.shortestPathsFrom(node: 0)
    print(paths)
}

main()