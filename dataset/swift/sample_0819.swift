import Foundation

class SupplyChainOptimizer {
    var nodes: Int
    var edges: [[Int]]
    var demand: [Int]
    var supply: [Int]
    var flow: [[Int]]

    init(nodes: Int, edges: [[Int]], demand: [Int], supply: [Int]) {
        self.nodes = nodes
        self.edges = edges
        self.demand = demand
        self.supply = supply
        self.flow = Array(repeating: Array(repeating: 0, count: nodes), count: nodes)
    }

    func findPath(source: Int, sink: Int, parent: inout [Int]) -> Bool {
        var visited = Array(repeating: false, count: nodes)
        var queue: [Int] = [source]
        visited[source] = true
        while !queue.isEmpty {
            let u = queue.removeFirst()
            for v in 0..<nodes {
                if !visited[v] && flow[u][v] < edges[u][v] {
                    queue.append(v)
                    visited[v] = true
                    parent[v] = u
                    if v == sink {
                        return true
                    }
                }
            }
        }
        return false
    }

    func maxFlow(source: Int, sink: Int) -> Int {
        var parent = Array(repeating: -1, count: nodes)
        var maxFlowValue = 0
        while findPath(source: source, sink: sink, parent: &parent) {
            var pathFlow = Int.max
            var s = sink
            while s != source {
                pathFlow = min(pathFlow, edges[parent[s]][s] - flow[parent[s]][s])
                s = parent[s]
            }
            var v = sink
            while v != source {
                let u = parent[v]
                flow[u][v] += pathFlow
                flow[v][u] -= pathFlow
                v = parent[v]
            }
            maxFlowValue += pathFlow
        }
        return maxFlowValue
    }
}

func main() {
    let nodes = 6
    let edges = [[0, 16, 13, 0, 0, 0], [0, 0, 10, 12, 0, 0], [0, 4, 0, 0, 14, 0], [0, 0, 9, 0, 0, 20], [0, 0, 0, 7, 0, 4], [0, 0, 0, 0, 0, 0]]
    let demand = [0, 0, 0, 0, 0, 25]
    let supply = [25, 0, 0, 0, 0, 0]
    let optimizer = SupplyChainOptimizer(nodes: nodes, edges: edges, demand: demand, supply: supply)
    let result = optimizer.maxFlow(source: 0, sink: 5)
    print("Maximum flow from source to sink is \(result)")
}

main()