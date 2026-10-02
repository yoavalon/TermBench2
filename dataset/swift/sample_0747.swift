func optimizeRoute(_ routes: [String: [(String, Int)]], _ visited: Set<String>, _ current: String, _ destination: String, _ cost: Int) -> Int {
    if current == destination {
        return cost
    }
    var minCost = Int.max
    for route in routes[current]! {
        if !visited.contains(route.0) {
            var newVisited = visited
            newVisited.insert(route.0)
            let newCost = optimizeRoute(routes, newVisited, route.0, destination, cost + route.1)
            if newCost < minCost {
                minCost = newCost
            }
        }
    }
    return minCost
}

func findOptimalPath(_ routes: [String: [(String, Int)]], _ start: String, _ end: String) -> Int {
    var visited = Set<String>()
    visited.insert(start)
    return optimizeRoute(routes, visited, start, end, 0)
}

let routes: [String: [(String, Int)]] = ["A": [("B", 10), ("C", 15)], "B": [("C", 35), ("D", 25)], "C": [("D", 30)], "D": []]
let start = "A"
let end = "D"
print(findOptimalPath(routes, start, end))