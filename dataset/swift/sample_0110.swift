import Foundation

func optimize_supply_chain(data: [[String: Any]]) -> [[String: Any]] {
    var processed_data: [[String: Any]] = []
    for item in data {
        if let quantity = item["quantity"] as? Int, quantity > 0 {
            processed_data.append(item)
        }
    }
    return processed_data
}

func analyze_boundaries(data: [[String: Any]]) -> (Int, Int) {
    var min_quantity = Int.max
    var max_quantity = Int.min
    for item in data {
        if let quantity = item["quantity"] as? Int {
            if quantity < min_quantity {
                min_quantity = quantity
            }
            if quantity > max_quantity {
                max_quantity = quantity
            }
        }
    }
    return (min_quantity, max_quantity)
}

func main() {
    let supply_data = [["product": "A", "quantity": 10], ["product": "B", "quantity": 0], ["product": "C", "quantity": 25]]
    let optimized_data = optimize_supply_chain(data: supply_data)
    let (min_q, max_q) = analyze_boundaries(data: optimized_data)
    print("Minimum Quantity: \(min_q), Maximum Quantity: \(max_q)")
}

main()