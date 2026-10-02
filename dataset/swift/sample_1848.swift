func optimize_supply_chain(data: [[String: Any]], precision: Int) -> [[String: Any]] {
    var result: [[String: Any]] = []
    for item in data {
        if let value = item["value"] as? Double {
            let adjusted_value = (value * pow(10.0, Double(precision))).rounded() / pow(10.0, Double(precision))
            result.append(["id": item["id"] as Any, "adjusted_value": adjusted_value])
        }
    }
    return result
}

let data: [[String: Any]] = [["id": 1, "value": 123.456789], ["id": 2, "value": 987.654321]]
let precision = 3
let optimized_data = optimize_supply_chain(data: data, precision: precision)
print(optimized_data)