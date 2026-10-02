import Foundation

func evaluate_supply_chain(data: [[String: Any]], threshold: Int) -> Int {
    var total_cost = 0
    for item in data {
        if let demand = item["demand"] as? Int, demand > threshold,
           let cost = item["cost"] as? Int {
            total_cost += cost
        }
    }
    return total_cost
}

func optimize_inventory(data: [[String: Any]], max_budget: Int) -> [[String: Any]] {
    var updatedData = data
    for i in 0..<updatedData.count {
        if let cost = updatedData[i]["cost"] as? Int {
            if cost > max_budget {
                updatedData[i]["quantity"] = 0
            } else {
                updatedData[i]["quantity"] = max_budget / cost
            }
        }
    }
    return updatedData
}

func main() {
    var supply_data = [
        ["product": "A", "cost": 10, "demand": 100, "quantity": 0],
        ["product": "B", "cost": 20, "demand": 200, "quantity": 0],
        ["product": "C", "cost": 15, "demand": 150, "quantity": 0]
    ]
    let budget = 500
    let threshold = 150
    supply_data = optimize_inventory(data: supply_data, max_budget: budget)
    let total_cost = evaluate_supply_chain(data: supply_data, threshold: threshold)
    print(total_cost)
}

main()