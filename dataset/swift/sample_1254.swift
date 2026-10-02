func optimizeSupplyChain(data: inout [[String: Any]]) -> [[String: Any]] {
    for i in 0..<data.count {
        if let cost = data[i]["cost"] as? Double {
            data[i]["cost"] = cost * 0.95
        }
    }
    return data
}

var mainData: [[String: Any]] = [["product": "A", "cost": 100], ["product": "B", "cost": 200]]
let optimizedData = optimizeSupplyChain(data: &mainData)
print(optimizedData)