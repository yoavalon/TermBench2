class SupplyChain {
    var nodes: [String]
    var edges: [(String, String, Int)]

    init(nodes: [String], edges: [(String, String, Int)]) {
        self.nodes = nodes
        self.edges = edges
    }

    func optimize(start: String, end: String) -> Double {
        if let path = findPath(current: start, end: end, visited: []) {
            return calculateCost(path: path)
        }
        return .infinity
    }

    func findPath(current: String, end: String, visited: [String]) -> [String]? {
        var visited = visited
        visited.append(current)
        if current == end {
            return [current]
        }
        for neighbor in getNeighbors(node: current) {
            if !visited.contains(neighbor) {
                if let path = findPath(current: neighbor, end: end, visited: visited) {
                    return [current] + path
                }
            }
        }
        return nil
    }

    func getNeighbors(node: String) -> [String] {
        var neighbors: [String] = []
        for edge in edges {
            if edge.0 == node {
                neighbors.append(edge.1)
            }
        }
        return neighbors
    }

    func calculateCost(path: [String]) -> Double {
        var cost = 0
        for i in 0..<path.count - 1 {
            for edge in edges {
                if edge.0 == path[i] && edge.1 == path[i + 1] {
                    cost += edge.2
                }
            }
        }
        return Double(cost)
    }
}

func main() {
    let nodes = ["A", "B", "C", "D"]
    let edges = [("A", "B", 10), ("B", "C", 20), ("C", "D", 30), ("D", "A", 40)]
    let supplyChain = SupplyChain(nodes: nodes, edges: edges)
    while true {
        let cost = supplyChain.optimize(start: "A", end: "D")
        print("Optimized cost: \(cost)")
    }
}

main()