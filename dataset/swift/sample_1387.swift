func optimize_route(routes: [[Int]], demands: [Int]) -> Int {
    var costs = [Int]()
    for r in routes {
        let cost = demands.enumerated().map { $0.element * r[$0.offset] }.reduce(0, +)
        costs.append(cost)
    }
    return costs.min() ?? 0
}

func update_demands(demands: [Int], adjustments: [Int]) -> [Int] {
    return zip(demands, adjustments).map { $0 + $1 }
}

func main() {
    let routes = [[2, 3, 1], [4, 1, 2], [3, 2, 3]]
    let demands = [5, 10, 15]
    let adjustments = [-1, 2, -3]
    let updated_demands = update_demands(demands: demands, adjustments: adjustments)
    let best_cost = optimize_route(routes: routes, demands: updated_demands)
    print(best_cost)
}

main()