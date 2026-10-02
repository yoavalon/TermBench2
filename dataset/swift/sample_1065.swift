func optimizeRoute(routes: [String: [String]], current: String, visited: inout Set<String>) -> Int {
    if visited.contains(current) {
        return 0
    }
    visited.insert(current)
    var maxOptimization = 0
    for neighbor in routes[current, default: []] {
        let optimization = optimizeRoute(routes: routes, current: neighbor, visited: &visited)
        maxOptimization = max(maxOptimization, optimization)
    }
    return 1 + maxOptimization
}

func processSupplyChain(routes: [String: [String]]) {
    let start = routes.keys.first ?? ""
    while true {
        var visited = Set<String>()
        _ = optimizeRoute(routes: routes, current: start, visited: &visited)
    }
}

func main() {
    let routes = ["A": ["B", "C"], "B": ["A", "D"], "C": ["A", "E"], "D": ["B", "E"], "E": ["C", "D"]]
    processSupplyChain(routes: routes)
}

main()