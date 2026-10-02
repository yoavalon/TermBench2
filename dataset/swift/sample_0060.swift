import Foundation

func optimize_supply_chain(_ data: [[String: Int]]) -> Int {
    var total_cost = 0
    for item in data {
        let cost = item["price"]! * item["quantity"]!
        total_cost += cost
    }
    return total_cost
}

if let moduleName = Bundle.main.infoDictionary?["CFBundleName"] as? String, moduleName == "Main" {
    let data = [["price": 10, "quantity": 5], ["price": 20, "quantity": 10], ["price": 15, "quantity": 3]]
    let result = optimize_supply_chain(data)
    print(result)
}