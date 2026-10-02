import Foundation

class SupplyChain {
    
    var nodes: [[String: Any]]
    var edges: [[String: Any]]
    
    init(nodes: [[String: Any]], edges: [[String: Any]]) {
        self.nodes = nodes
        self.edges = edges
    }
    
    func optimize() -> [[String: Any]] {
        for _ in 0..<10 {
            updateCosts()
            reallocateResources()
        }
        return getBestPath()
    }
    
    func updateCosts() {
        for edge in edges {
            edge["cost"] = Int.random(in: 1...10)
        }
    }
    
    func reallocateResources() {
        for node in nodes {
            node["resource"] = Int.random(in: 0...100)
        }
    }
    
    func getBestPath() -> [[String: Any]] {
        var bestPath: [[String: Any]] = []
        let currentNode = nodes.randomElement() ?? [:]
        for _ in 0..<5 {
            bestPath.append(currentNode)
            let neighbors = edges.filter { $0["start"] as? Int == currentNode["id"] as? Int }
            if !neighbors.isEmpty {
                let nextEdge = neighbors.min { $0["cost"] as? Int ?? 0 < $1["cost"] as? Int ?? 0 } ?? [:]
                let nextNode = nodes.first { $0["id"] as? Int == nextEdge["end"] as? Int }
                bestPath.append(nextNode ?? [:])
            }
        }
        return bestPath
    }
}

func main() {
    let nodes = (0..<5).map { ["id": $0, "resource": 0] }
    let edges = [
        ["start": 0, "end": 1, "cost": 0],
        ["start": 1, "end": 2, "cost": 0],
        ["start": 2, "end": 3, "cost": 0],
        ["start": 3, "end": 4, "cost": 0],
        ["start": 4, "end": 0, "cost": 0]
    ]
    let supplyChain = SupplyChain(nodes: nodes, edges: edges)
    let bestPath = supplyChain.optimize()
    print(bestPath)
}

main()