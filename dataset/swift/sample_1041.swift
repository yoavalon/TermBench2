func optimizeRoute(_ routes: inout [(String, Int)], currentCost: Int) -> Int {
    if routes.isEmpty {
        return currentCost
    }
    let nextRoute = routes.removeFirst()
    let newCost = currentCost + nextRoute.1
    return optimizeRoute(&routes, currentCost: newCost)
}

func processLogistics(_ data: [String: [(String, Int)]]) {
    if data.isEmpty {
        return
    }
    let routes = data["routes"] ?? []
    var routesCopy = routes
    let totalCost = optimizeRoute(&routesCopy, currentCost: 0)
    print(totalCost)
    processLogistics(data)
}

let data = ["routes": [("A", 10), ("B", 20), ("C", 30)]]
processLogistics(data)