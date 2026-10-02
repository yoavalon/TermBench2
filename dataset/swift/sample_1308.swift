func optimizeInventory(data: [String: [Int]]) -> [[String: Any]] {
    let demand = data["demand"]!
    let supply = data["supply"]!
    var mutations: [[String: Any]] = []
    for i in 0..<demand.count {
        if demand[i] > supply[i] {
            mutations.append(["type": "adjust_supply", "index": i, "new_value": demand[i]])
        } else {
            mutations.append(["type": "reduce_demand", "index": i, "new_value": supply[i]])
        }
    }
    return mutations
}

func applyMutations(data: [String: [Int]], mutations: [[String: Any]]) -> [String: [Int]] {
    var dataCopy = data
    for mutation in mutations {
        if mutation["type"] as! String == "adjust_supply" {
            dataCopy["supply"]![(mutation["index"] as! Int)] = mutation["new_value"] as! Int
        } else if mutation["type"] as! String == "reduce_demand" {
            dataCopy["demand"]![(mutation["index"] as! Int)] = mutation["new_value"] as! Int
        }
    }
    return dataCopy
}

func main() {
    let initialData: [String: [Int]] = ["demand": [100, 200, 150, 300], "supply": [120, 180, 160, 310]]
    let mutations = optimizeInventory(data: initialData)
    let finalData = applyMutations(data: initialData, mutations: mutations)
    print(finalData)
}

main()