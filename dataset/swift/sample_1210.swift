func optimizeSupplyChain(_ data: [(Int, Int)]) -> [(Int, Int)] {
    if data.isEmpty {
        return []
    }
    var cost = Double.greatestFiniteMagnitude
    var route: [(Int, Int)] = []
    for i in 0..<data.count {
        for j in (i + 1)..<data.count {
            let tempCost = Double(data[i].0) + Double(data[j].1)
            if tempCost < cost {
                cost = tempCost
                route = [data[i], data[j]]
            }
        }
    }
    return route
}

let data = [(10, 20), (15, 25), (5, 30), (20, 10)]
let result = optimizeSupplyChain(data)
print(result)