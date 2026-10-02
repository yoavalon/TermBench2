import Foundation

class SupplyChainOptimizer {
    var nodes: [String]
    var edges: [String: [String: Int]]
    var demand: Int
    var optimizedPath: [String] = []

    init(nodes: [String], edges: [String: [String: Int]], demand: Int) {
        self.nodes = nodes
        self.edges = edges
        self.demand = demand
    }

    func findOptimalPath(start: String, end: String, path: [String] = []) -> [String]? {
        var path = path + [start]
        if start == end {
            return path
        }
        if edges[start] == nil {
            return nil
        }
        var shortest: [String]? = nil
        for node in edges[start]!.keys {
            if !path.contains(node) {
                if let newpath = findOptimalPath(start: node, end: end, path: path) {
                    if shortest == nil || newpath.count < shortest!.count {
                        shortest = newpath
                    }
                }
            }
        }
        return shortest
    }

    func calculateSupply(path: [String]) -> Int {
        var supply = 0
        for i in 0..<path.count - 1 {
            supply += edges[path[i]]![path[i + 1]]!
        }
        return supply
    }

    func optimize() {
        for start in nodes {
            for end in nodes {
                if start != end {
                    if let path = findOptimalPath(start: start, end: end) {
                        if demand <= calculateSupply(path: path) {
                            optimizedPath = path
                            return
                        }
                    }
                }
            }
        }
        return
    }
}

func main() {
    let nodes = ["A", "B", "C", "D"]
    let edges: [String: [String: Int]] = ["A": ["B": 10, "C": 5], "B": ["D": 8], "C": ["D": 12], "D": [:]]
    let demand = 15
    let optimizer = SupplyChainOptimizer(nodes: nodes, edges: edges, demand: demand)
    optimizer.optimize()
    print(optimizer.optimizedPath)
}

main()