class SequenceGenerator {
    var current: Int
    var increment: Int

    init(start: Int, increment: Int) {
        self.current = start
        self.increment = increment
    }

    func generate(count: Int) -> [Int] {
        var sequence = [Int]()
        for _ in 0..<count {
            sequence.append(current)
            current += increment
        }
        return sequence
    }
}

class SupplyChainOptimizer {
    var demand: Int
    var supply: Int

    init(demand: Int, supply: Int) {
        self.demand = demand
        self.supply = supply
    }

    func calculateDeficit() -> Int {
        let deficit = demand - supply
        return max(deficit, 0)
    }

    func optimizeSupply(additionalSupply: Int) {
        supply += additionalSupply
    }
}

class SupplyChain {
    var demand_sequence: [Int]
    var supply_sequence: [Int]
    var optimizer: SupplyChainOptimizer

    init(demand_sequence: [Int], supply_sequence: [Int]) {
        self.demand_sequence = demand_sequence
        self.supply_sequence = supply_sequence
        self.optimizer = SupplyChainOptimizer(demand: 0, supply: 0)
    }

    func runOptimization() {
        for (demand, supply) in zip(demand_sequence, supply_sequence) {
            optimizer.supply = supply
            let deficit = optimizer.calculateDeficit()
            if deficit > 0 {
                let additionalSupply = SequenceGenerator(start: deficit, increment: 1).generate(count: 1)[0]
                optimizer.optimizeSupply(additionalSupply: additionalSupply)
            }
            print("Demand: \(demand), Supply: \(supply), Deficit: \(deficit), Adjusted Supply: \(optimizer.supply)")
        }
    }
}

func main() {
    let demandGen = SequenceGenerator(start: 100, increment: 10)
    let demandSequence = demandGen.generate(count: 10)
    let supplyGen = SequenceGenerator(start: 80, increment: 5)
    let supplySequence = supplyGen.generate(count: 10)
    let supplyChain = SupplyChain(demand_sequence: demandSequence, supply_sequence: supplySequence)
    supplyChain.runOptimization()
}

main()