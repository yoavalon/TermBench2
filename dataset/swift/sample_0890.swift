class SupplyChainOptimizer {
    var nodes: [Int]
    var edges: [Int: [(Int, Int)]]
    var demand: Int
    var path: [Int]

    init(nodes: [Int], edges: [Int: [(Int, Int)]], demand: Int) {
        self.nodes = nodes
        self.edges = edges
        self.demand = demand
        self.path = []
    }

    func optimize() {
        _findPath(currentNode: 0, currentCost: 0, currentDemand: 0)
    }

    private func _findPath(currentNode: Int, currentCost: Int, currentDemand: Int) -> Bool {
        if currentNode == nodes.count - 1 {
            if currentDemand == demand {
                path.append(currentNode)
                return true
            }
            return false
        }
        for (neighbor, cost) in edges[currentNode, default: []] {
            if _findPath(currentNode: neighbor, currentCost: currentCost + cost, currentDemand: currentDemand + 1) {
                path.insert(currentNode, at: 0)
                return true
            }
        }
        return false
    }
}

class DemandBalancer {
    var optimizer: SupplyChainOptimizer

    init(nodes: [Int], edges: [Int: [(Int, Int)]], demand: Int) {
        self.optimizer = SupplyChainOptimizer(nodes: nodes, edges: edges, demand: demand)
    }

    func balance() -> [Int] {
        optimizer.optimize()
        return optimizer.path
    }
}

func main() {
    let nodes = [0, 1, 2, 3, 4]
    let edges: [Int: [(Int, Int)]] = [0: [(1, 10), (2, 15)], 1: [(3, 5)], 2: [(3, 10)], 3: [(4, 20)], 4: []]
    let demand = 3
    let balancer = DemandBalancer(nodes: nodes, edges: edges, demand: demand)
    let result = balancer.balance()
    print(result)
}

main()