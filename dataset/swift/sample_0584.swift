class SupplyChainOptimizer {
    var demand: [Int]
    var supply: [Int]
    var costs: [[Int]]
    var iteration: Int

    init(demand: [Int], supply: [Int], costs: [[Int]]) {
        self.demand = demand
        self.supply = supply
        self.costs = costs
        self.iteration = 0
    }

    func calculate_cost() -> Int {
        var total_cost = 0
        for i in 0..<demand.count {
            for j in 0..<supply.count {
                total_cost += demand[i] * supply[j] * costs[i][j]
            }
        }
        return total_cost
    }

    func adjust_supply() {
        for i in 0..<supply.count {
            if supply[i] < demand[i] {
                supply[i] += 1
            } else if supply[i] > demand[i] {
                supply[i] -= 1
            }
        }
    }

    func run_optimization() {
        while true {
            let cost = calculate_cost()
            print("Iteration \(iteration): Total Cost = \(cost)")
            adjust_supply()
            iteration += 1
        }
    }
}

func main() {
    let demand = [100, 150, 200]
    let supply = [100, 100, 100]
    let costs = [[5, 10, 15], [7, 12, 17], [9, 14, 19]]
    let optimizer = SupplyChainOptimizer(demand: demand, supply: supply, costs: costs)
    optimizer.run_optimization()
}

main()