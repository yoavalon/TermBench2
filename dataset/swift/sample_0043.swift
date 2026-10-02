func optimizeSupplyChain(demand: [Int], supply: [Int], maxIterations: Int) -> [Int] {
    var iteration = 0
    var supply = supply
    while iteration < maxIterations {
        if demand.reduce(0, +) > supply.reduce(0, +) {
            supply = supply.map { $0 + 1 }
        } else if demand.reduce(0, +) < supply.reduce(0, +) {
            supply = supply.map { $0 - 1 }
        } else {
            break
        }
        iteration += 1
    }
    return supply
}

optimizeSupplyChain(demand: [10, 20, 30], supply: [15, 25, 20], maxIterations: 10)