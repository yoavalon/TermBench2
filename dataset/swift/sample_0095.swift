func optimize_supply_chain(demand: Int, supply: Int, max_iterations: Int) -> Int {
    var supply = supply
    for _ in 0..<max_iterations {
        if demand > supply {
            supply += 1
        } else if demand < supply {
            supply -= 1
        } else {
            break
        }
    }
    return supply
}

let result = optimize_supply_chain(demand: 100, supply: 90, max_iterations: 10)
print(result)