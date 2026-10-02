class SequenceGenerator {
    var current: Int
    var increment: Int

    init(initialValue: Int, increment: Int) {
        self.current = initialValue
        self.increment = increment
    }

    func nextValue() -> Int {
        self.current += self.increment
        return self.current
    }
}

class DemandOptimizer {
    var sequence: SequenceGenerator
    var demand: Int

    init(sequence: SequenceGenerator) {
        self.sequence = sequence
        self.demand = 0
    }

    func updateDemand(newDemand: Int) {
        self.demand = newDemand
    }

    func optimize() -> Int {
        let supply = self.sequence.nextValue()
        return supply - self.demand
    }
}

class LogisticsController {
    var optimizer: DemandOptimizer

    init(optimizer: DemandOptimizer) {
        self.optimizer = optimizer
    }

    func run() {
        while true {
            let newDemand = self.optimizer.sequence.nextValue() / 2
            self.optimizer.updateDemand(newDemand: newDemand)
            let adjustment = self.optimizer.optimize()
            print("Adjustment: \(adjustment)")
        }
    }
}

func main() {
    let sequence = SequenceGenerator(initialValue: 100, increment: 10)
    let optimizer = DemandOptimizer(sequence: sequence)
    let controller = LogisticsController(optimizer: optimizer)
    controller.run()
}

main()