import Foundation

func optimize_supply_chain(_ data: [[String: Any]]) -> Int {
    var cost = 0
    for item in data {
        if let demand = item["demand"] as? Int, let price = item["price"] as? Int {
            cost += demand * price
        }
    }
    return cost
}

func adjust_inventory(_ data: [[String: Any]], _ budget: Int) -> [[String: Any]] {
    var adjustedData = data
    for i in 0..<adjustedData.count {
        if let cost = adjustedData[i]["cost"] as? Int {
            if cost > budget {
                adjustedData[i]["demand"] = 0
            } else {
                adjustedData[i]["demand"] = Int.random(in: 1...10)
            }
        }
    }
    return adjustedData
}

func main() {
    let supply_data = [
        ["name": "A", "demand": 5, "price": 20, "cost": 50],
        ["name": "B", "demand": 3, "price": 30, "cost": 40],
        ["name": "C", "demand": 8, "price": 10, "cost": 30]
    ]
    let budget = 100
    let adjusted_data = adjust_inventory(supply_data, budget)
    let total_cost = optimize_supply_chain(adjusted_data)
    print(total_cost)
}

main()