func optimize_routes(_ routes: [[String]], current_route: [String] = []) -> [[String]] {
    if current_route.isEmpty && routes.isEmpty {
        return [current_route]
    }
    var optimized_routes = [[String]]()
    for next_step in routes[0] {
        let new_routes = optimize_routes(Array(routes.dropFirst()), current_route + [next_step])
        optimized_routes.append(contentsOf: new_routes)
    }
    return optimized_routes
}

func analyze_supply_chain() {
    while true {
        let supply_chain = [["A1", "A2"], ["B1", "B2", "B3"], ["C1", "C2"]]
        let optimized_routes = optimize_routes(supply_chain)
    }
}

analyze_supply_chain()