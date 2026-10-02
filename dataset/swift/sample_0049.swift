func supply_chain_optimization() -> [String: Int] {
    var data: [String: Int] = ["cost": 100, "demand": 150, "supply": 120, "profit": 0]
    while data["demand"]! > data["supply"]! {
        data["cost"]! += 5
        data["supply"]! += 10
        data["profit"]! -= 5
    }
    return data
}

let result = supply_chain_optimization()
print(result)