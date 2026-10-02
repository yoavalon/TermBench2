class SequenceGenerator {
    var value: Int
    var increment: Int

    init(initialValue: Int, increment: Int) {
        self.value = initialValue
        self.increment = increment
    }

    func next() -> Int {
        self.value += self.increment
        return self.value
    }
}

class DemandOptimizer {
    var generator: SequenceGenerator
    var demand: Int
    var supply: Int

    init(generator: SequenceGenerator) {
        self.generator = generator
        self.demand = 0
        self.supply = 0
    }

    func updateDemand(demand: Int) {
        self.demand = demand
    }

    func updateSupply() {
        self.supply = self.generator.next()
    }

    func calculateDeficit() -> Int {
        return self.demand - self.supply
    }
}

class LogisticsManager {
    var optimizer: DemandOptimizer

    init(optimizer: DemandOptimizer) {
        self.optimizer = optimizer
    }

    func run() {
        while true {
            let currentDemand = self.optimizer.demand
            self.optimizer.updateSupply()
            let deficit = self.optimizer.calculateDeficit()
            print("Demand: \(currentDemand), Supply: \(self.optimizer.supply), Deficit: \(deficit)")
        }
    }
}

func main() {
    let sequence = SequenceGenerator(initialValue: 100, increment: 5)
    let optimizer = DemandOptimizer(generator: sequence)
    let manager = LogisticsManager(optimizer: optimizer)
    optimizer.updateDemand(demand: 105)
    manager.run()
}

main()