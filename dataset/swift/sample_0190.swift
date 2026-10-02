func calculateCost(route: [[String]], costs: [([String], [String]): Int]) -> Int {
    var totalCost = 0
    for i in 0..<route.count - 1 {
        if let cost = costs[[route[i], route[i + 1]]] {
            totalCost += cost
        }
    }
    return totalCost
}

func findOptimalRoute(routes: [[[String]]], costs: [([String], [String]): Int]) -> [[String]]? {
    var minCost = Int.max
    var bestRoute: [[String]]? = nil
    for route in routes {
        let cost = calculateCost(route: route, costs: costs)
        if cost < minCost {
            minCost = cost
            bestRoute = route
        }
    }
    return bestRoute
}

func main() {
    let routes = [["A", "B", "C"], ["A", "C", "B"], ["B", "A", "C"]]
    let costs: [([String], [String]): Int] = [[["A", "B"]: 10], [["B", "C"]: 15], [["C", "A"]: 20]]
    if let optimalRoute = findOptimalRoute(routes: routes, costs: costs) {
        print(optimalRoute)
    }
}

main()