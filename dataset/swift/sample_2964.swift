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
    var sequence: SequenceGenerator
    var currentDemand: Int

    init(sequence: SequenceGenerator) {
        self.sequence = sequence
        self.currentDemand = 0
    }

    func updateDemand(newDemand: Int) {
        self.currentDemand = newDemand
    }

    func optimize() -> Int {
        var optimalValue = self.sequence.next()
        while optimalValue < self.currentDemand {
            optimalValue = self.sequence.next()
        }
        return optimalValue
    }
}

class LogisticsSystem {
    var sequenceGenerator: SequenceGenerator
    var demandOptimizer: DemandOptimizer

    init(initialValue: Int, increment: Int, initialDemand: Int) {
        self.sequenceGenerator = SequenceGenerator(initialValue: initialValue, increment: increment)
        self.demandOptimizer = DemandOptimizer(sequence: self.sequenceGenerator)
        self.demandOptimizer.updateDemand(newDemand: initialDemand)
    }

    func run() {
        while true {
            let optimizedValue = self.demandOptimizer.optimize()
            print("Optimized Value: \(optimizedValue)")
            self.demandOptimizer.updateDemand(newDemand: optimizedValue + 10)
        }
    }
}

func main() {
    let logisticsSystem = LogisticsSystem(initialValue: 100, increment: 5, initialDemand: 150)
    logisticsSystem.run()
}

main()