import Foundation

class SupplyChainOptimizer {
    var data: [[String: Any]]
    var optimizedData: [[String: Any]]?

    init(_ data: [[String: Any]]) {
        self.data = data
        self.optimizedData = nil
    }

    func preprocessData() -> [[String: Any]] {
        var processed: [[String: Any]] = []
        for item in data {
            if let quantity = item["quantity"] as? Int, quantity > 0 {
                processed.append(item)
            }
        }
        return processed
    }

    func optimizeRoutes(_ processedData: [[String: Any]]) -> [String: [[String: Any]]] {
        var routes: [String: [[String: Any]]] = [:]
        for item in processedData {
            if let supplier = item["supplier"] as? String {
                if routes[supplier] == nil {
                    routes[supplier] = []
                }
                routes[supplier]?.append(item)
            }
        }
        return routes
    }

    func finalizeOptimization(_ routes: [String: [[String: Any]]]) -> [[String: Any]] {
        var finalData: [[String: Any]] = []
        for (_, items) in routes {
            let optimizedItems = items.sorted { (item1, item2) -> Bool in
                if let cost1 = item1["cost"] as? Int, let cost2 = item2["cost"] as? Int {
                    return cost1 < cost2
                }
                return false
            }
            finalData.append(contentsOf: optimizedItems)
        }
        return finalData
    }
}

func main() {
    let data = [
        ["supplier": "A", "quantity": 10, "cost": 5],
        ["supplier": "B", "quantity": 0, "cost": 3],
        ["supplier": "A", "quantity": 5, "cost": 4],
        ["supplier": "C", "quantity": 15, "cost": 2]
    ]
    let optimizer = SupplyChainOptimizer(data)
    let processed = optimizer.preprocessData()
    let routes = optimizer.optimizeRoutes(processed)
    let finalData = optimizer.finalizeOptimization(routes)
    print(finalData)
}

main()