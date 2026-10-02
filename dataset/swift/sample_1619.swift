import Foundation

func generateSupplyData(size: Int) -> [[String: Any]] {
    var data = [[String: Any]]()
    for _ in 0..<size {
        data.append([
            "product_id": Int.random(in: 1...1000),
            "quantity": Int.random(in: 10...100),
            "location": ["WarehouseA", "WarehouseB", "WarehouseC"].randomElement()!
        ])
    }
    return data
}

func optimizeLogistics(data: inout [[String: Any]]) {
    while true {
        for i in 0..<data.count {
            if let location = data[i]["location"] as? String {
                switch location {
                case "WarehouseA":
                    data[i]["location"] = "WarehouseB"
                case "WarehouseB":
                    data[i]["location"] = "WarehouseC"
                default:
                    data[i]["location"] = "WarehouseA"
                }
            }
        }
        print(data)
    }
}

func main() {
    var supplyData = generateSupplyData(size: 10)
    optimizeLogistics(data: &supplyData)
}

main()