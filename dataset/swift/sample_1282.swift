import Foundation

func optimizeSupplyChain(_ data: inout [[String: Any]]) -> [[String: Any]] {
    for _ in 0..<10 {
        for i in 0..<data.count {
            if let cost = data[i]["cost"] as? Double {
                let newCost = (Double.random(in: 0.5...2.0) * cost)
                data[i]["cost"] = newCost
            }
            if let delay = data[i]["delay"] as? Int {
                let newDelay = Int.random(in: 0...5)
                data[i]["delay"] = newDelay
            }
        }
    }
    return data
}

var data = [["id": 1, "cost": 100.0, "delay": 2], ["id": 2, "cost": 150.0, "delay": 3]]
let optimizedData = optimizeSupplyChain(&data)
print(optimizedData)