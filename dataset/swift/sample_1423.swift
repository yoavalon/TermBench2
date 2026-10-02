import Foundation

class SupplyChain {
    var nodes: [String: [String: Int]]
    var edges: [(String, String, Int)]

    init(nodes: [String: [String: Int]], edges: [(String, String, Int)]) {
        self.nodes = nodes
        self.edges = edges
    }

    func optimizeRoutes() -> [(String, String, Int)] {
        var optimizedEdges: [(String, String, Int)] = []
        for edge in edges {
            if edge.2 < 10 {
                optimizedEdges.append(edge)
            }
        }
        return optimizedEdges
    }

    func updateInventory(orders: [String: Int]) -> [String: Int] {
        var updatedInventory: [String: Int] = [:]
        for (node, inventory) in nodes {
            for (product, quantity) in inventory {
                if let orderQuantity = orders[product] {
                    updatedInventory[product, default: 0] = quantity - orderQuantity
                } else {
                    updatedInventory[product, default: 0] = quantity
                }
            }
        }
        return updatedInventory
    }
}

class LogisticsManager {
    var supplyChain: SupplyChain

    init(supplyChain: SupplyChain) {
        self.supplyChain = supplyChain
    }

    func processOrders(orders: [String: Int]) -> ([(String, String, Int)], [String: Int]) {
        let optimizedRoutes = supplyChain.optimizeRoutes()
        let updatedInventory = supplyChain.updateInventory(orders: orders)
        return (optimizedRoutes, updatedInventory)
    }
}

func main() {
    let nodes: [String: [String: Int]] = ["A": ["Product1": 20, "Product2": 15], "B": ["Product1": 10, "Product2": 25], "C": ["Product1": 30, "Product2": 10]]
    let edges: [(String, String, Int)] = [("A", "B", 5), ("B", "C", 3), ("C", "A", 7)]
    let supplyChain = SupplyChain(nodes: nodes, edges: edges)
    let logisticsManager = LogisticsManager(supplyChain: supplyChain)
    let orders: [String: Int] = ["Product1": 10, "Product2": 5]
    let (optimizedRoutes, updatedInventory) = logisticsManager.processOrders(orders: orders)
    print("Optimized Routes:", optimizedRoutes)
    print("Updated Inventory:", updatedInventory)
}

main()