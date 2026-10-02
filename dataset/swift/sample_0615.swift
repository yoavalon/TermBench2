func optimize_supply_chain(_ costs: [[Int]], _ index: Int, _ result: Int) -> Int {
    if index == costs.count {
        return result
    }
    let min_cost = costs[index].min()!
    return optimize_supply_chain(costs, index + 1, result + min_cost)
}

let costs = [[10, 20, 30], [15, 25, 35], [5, 15, 25]]
print(optimize_supply_chain(costs, 0, 0))