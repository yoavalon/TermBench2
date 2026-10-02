class SupplyChainOptimization {
    var demand: Int
    var supply: Int
    var cost: Double
    var iteration: Int
    let maxIterations = 100

    init(demand: Int, supply: Int, cost: Double) {
        self.demand = demand
        self.supply = supply
        self.cost = cost
        self.iteration = 0
    }

    func calculateShortage() -> Int {
        return max(0, demand - supply)
    }

    func adjustSupply() -> Int {
        let shortage = calculateShortage()
        if shortage > 0 {
            let adjustment = min(shortage, supply * 10 / 100)
            supply += adjustment
            return adjustment
        }
        return 0
    }

    func updateCost(adjustment: Int) {
        if adjustment > 0 {
            cost += Double(adjustment) * 0.05
        }
    }

    func runOptimization() {
        while iteration < maxIterations {
            let shortage = calculateShortage()
            if shortage == 0 {
                break
            }
            let adjustment = adjustSupply()
            updateCost(adjustment: adjustment)
            iteration += 1
        }
    }
}

func main() {
    let demand = 500
    let supply = 450
    let cost = 1000.0
    let optimizer = SupplyChainOptimization(demand: demand, supply: supply, cost: cost)
    optimizer.runOptimization()
    print("Final Supply: \(optimizer.supply), Final Cost: \(optimizer.cost)")
}

main()