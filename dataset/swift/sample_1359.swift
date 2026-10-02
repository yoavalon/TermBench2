import Foundation

func generate_shipments(data: [[String: Any]]) -> [[String: Any]] {
    var mutated_data: [[String: Any]] = []
    for item in data {
        var new_item = item
        if let quantity = new_item["quantity"] as? Int {
            new_item["quantity"] = Int(Double(quantity) * (0.8...1.2).randomElement()!)
        }
        if let lead_time = new_item["lead_time"] as? Int {
            new_item["lead_time"] = Int(Double(lead_time) * (0.9...1.1).randomElement()!)
        }
        mutated_data.append(new_item)
    }
    return mutated_data
}

func optimize_inventory(data: [[String: Any]]) -> [[String: Any]] {
    var optimized_data: [[String: Any]] = []
    for item in data {
        var new_item = item
        if let quantity = new_item["quantity"] as? Int, quantity > 100 {
            new_item["quantity"] = 100
        }
        if let lead_time = new_item["lead_time"] as? Int, lead_time < 5 {
            new_item["lead_time"] = 5
        }
        optimized_data.append(new_item)
    }
    return optimized_data
}

func main() {
    let initial_data = [
        ["item": "A", "quantity": 120, "lead_time": 4],
        ["item": "B", "quantity": 90, "lead_time": 6],
        ["item": "C", "quantity": 150, "lead_time": 3]
    ]
    let mutated_data = generate_shipments(data: initial_data)
    let optimized_data = optimize_inventory(data: mutated_data)
    print(optimized_data)
}

main()