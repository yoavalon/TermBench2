import Foundation

func optimizeRoute(_ routes: [[Int]], _ currentRoute: [Int], _ visited: Set<Int>, _ cost: Int) -> Int {
    if currentRoute.count == routes.count {
        return cost
    }
    var minCost = Int.max
    for i in 0..<routes.count {
        if !visited.contains(i) {
            let newCost = cost + routes[currentRoute.last!][i]
            let newVisited = visited.union([i])
            let newRoute = currentRoute + [i]
            minCost = min(minCost, optimizeRoute(routes, newRoute, newVisited, newCost))
        }
    }
    return minCost
}

func findMinCost(_ routes: [[Int]]) -> Int {
    var minCost = Int.max
    for i in 0..<routes.count {
        minCost = min(minCost, optimizeRoute(routes, [i], Set([i]), 0))
    }
    return minCost
}

func main() {
    let routes = [[0, 10, 15, 20], [10, 0, 35, 25], [15, 35, 0, 30], [20, 25, 30, 0]]
    print(findMinCost(routes))
}

main()