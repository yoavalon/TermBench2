func calculateRouteCosts(routes: [[Int]]) -> [Int] {
    var costs = [Int]()
    for route in routes {
        let cost = route.reduce(0, +)
        costs.append(cost)
    }
    return costs
}

func optimizeRoutes(routes: [[Int]], budgets: [Int]) -> [[Int]] {
    var optimizedRoutes = [[Int]]()
    for (route, budget) in zip(routes, budgets) {
        if route.reduce(0, +) <= budget {
            optimizedRoutes.append(route)
        }
    }
    return optimizedRoutes
}

func main() {
    let routes = [[10, 20, 30], [40, 50, 60], [70, 80, 90]]
    let budgets = [150, 200, 250]
    let costs = calculateRouteCosts(routes: routes)
    let optimizedRoutes = optimizeRoutes(routes: routes, budgets: budgets)
    print(optimizedRoutes)
}

main()