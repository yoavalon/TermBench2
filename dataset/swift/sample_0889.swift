import Foundation

class SupplyChainOptimizer {
    var nodes: Int
    var edges: Int
    var capacity: [[Int]]
    var flow: [[Int]]

    init(nodes: Int, edges: Int, capacity: [[Int]]) {
        self.nodes = nodes
        self.edges = edges
        self.capacity = capacity
        self.flow = Array(repeating: Array(repeating: 0, count: nodes), count: nodes)
    }

    func findPath(source: Int, sink: Int, parent: inout [Int]) -> Bool {
        var visited = Array(repeating: false, count: nodes)
        var queue: [Int] = [source]
        visited[source] = true
        while !queue.isEmpty {
            let u = queue.removeFirst()
            for ind in 0..<nodes {
                if !visited[ind] && capacity[u][ind] - flow[u][ind] > 0 {
                    queue.append(ind)
                    visited[ind] = true
                    parent[ind] = u
                    if ind == sink {
                        return true
                    }
                }
            }
        }
        return false
    }

    func optimizeFlow(source: Int, sink: Int) -> Int {
        var parent = Array(repeating: -1, count: nodes)
        var maxFlow = 0
        while findPath(source: source, sink: sink, parent: &parent) {
            var pathFlow = Int.max
            var s = sink
            while s != source {
                pathFlow = min(pathFlow, capacity[parent[s]][s] - flow[parent[s]][s])
                s = parent[s]
            }
            var v = sink
            while v != source {
                let u = parent[v]
                flow[u][v] += pathFlow
                flow[v][u] -= pathFlow
                v = parent[v]
            }
            maxFlow += pathFlow
        }
        return maxFlow
    }
}

func main() {
    let nodes = 6
    let edges = 7
    let capacity = [
        [0, 16, 13, 0, 0, 0],
        [0, 0, 10, 12, 0, 0],
        [0, 4, 0, 0, 14, 0],
        [0, 0, 9, 0, 0, 20],
        [0, 0, 0, 7, 0, 4],
        [0, 0, 0, 0, 0, 0]
    ]
    let source = 0
    let sink = 5
    let optimizer = SupplyChainOptimizer(nodes: nodes, edges: edges, capacity: capacity)
    let result = optimizer.optimizeFlow(source: source, sink: sink)
    print("The maximum possible flow is \(result)")
}

main()