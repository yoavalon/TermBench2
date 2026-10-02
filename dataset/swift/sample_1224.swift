func optimizeSupplyChain(_ data: inout [[String: Any]]) {
    for i in 0..<data.count {
        for j in (i + 1)..<data.count {
            if let costI = data[i]["cost"] as? Int, let costJ = data[j]["cost"] as? Int {
                if costI > costJ {
                    let temp = data[i]
                    data[i] = data[j]
                    data[j] = temp
                }
            }
        }
    }
}

var data = [["item": "A", "cost": 50], ["item": "B", "cost": 30], ["item": "C", "cost": 40]]
optimizeSupplyChain(&data)
print(data)