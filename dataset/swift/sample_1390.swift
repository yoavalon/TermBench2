import Foundation

func load_data() -> [[String: Any]] {
    var data: [[String: Any]] = []
    for i in 1...100 {
        let quantity = Int.random(in: 1...100)
        let cost = Double.random(in: 0...1000)
        data.append(["id": i, "quantity": quantity, "cost": cost])
    }
    return data
}

func optimize_supply_chain(data: [[String: Any]]) -> [[String: Any]] {
    return data.map { row in
        var newRow = row
        if let quantity = row["quantity"] as? Int, let cost = row["cost"] as? Double {
            newRow["optimized_quantity"] = Int(Double(quantity) * 1.1)
            newRow["total_cost"] = Double(newRow["optimized_quantity"] as? Int ?? 0) * cost
        }
        return newRow
    }
}

func process_data() -> [[String: Any]] {
    let df = load_data()
    let optimized_df = optimize_supply_chain(data: df)
    return optimized_df
}

func main() {
    let result = process_data()
    for row in result.prefix(5) {
        print(row)
    }
}

main()