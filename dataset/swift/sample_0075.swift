func optimizeSupplyChain(_ data: [String: Any]) -> [String] {
    
    func calculateCost(_ route: [String]) -> Int {
        let distances = data["distances"] as! [String: [String: Int]]
        var totalCost = 0
        for i in 0..<(route.count - 1) {
            totalCost += distances[route[i]]![route[i + 1]]!
        }
        return totalCost
    }
    
    func findBestRoute(_ routes: [[String]]) -> [String] {
        return routes.min(by: { calculateCost($0) < calculateCost($1) })!
    }
    
    let routes = data["routes"] as! [[String]]
    let bestRoute = findBestRoute(routes)
    return bestRoute
}

let data: [String: Any] = ["distances": ["A": ["B": 10, "C": 15], "B": ["A": 10, "C": 35], "C": ["A": 15, "B": 35]], "routes": [["A", "B", "C"], ["A", "C", "B"]]]
optimizeSupplyChain(data)