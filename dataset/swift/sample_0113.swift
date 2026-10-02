import Foundation

func generateSupplyData(numItems: Int) -> [[String: Any]] {
    var data: [[String: Any]] = []
    for _ in 0..<numItems {
        data.append([
            "item_id": Int.random(in: 1...1000),
            "quantity": Int.random(in: 10...100),
            "cost": Double.random(in: 5.0...20.0)
        ])
    }
    return data
}

func optimizeSupplyChain(data: [[String: Any]]) -> [[String: Any]] {
    var totalCost: Double = 0
    for item in data {
        if let quantity = item["quantity"] as? Int, let cost = item["cost"] as? Double {
            totalCost += Double(quantity) * cost
        }
    }
    let averageCost = totalCost / Double(data.count)
    var optimizedData: [[String: Any]] = []
    for item in data {
        if let cost = item["cost"] as? Double, cost <= averageCost {
            optimizedData.append(item)
        }
    }
    return optimizedData
}

func main() {
    let numItems = 50
    let supplyData = generateSupplyData(numItems: numItems)
    let optimizedData = optimizeSupplyChain(data: supplyData)
    print("Optimized supply chain data: \(optimizedData)")
}

main()