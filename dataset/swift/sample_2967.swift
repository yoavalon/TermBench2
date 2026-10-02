class SequenceGenerator {
    var state = 0

    func generate() -> AnySequence<Int> {
        return AnySequence {
            return AnyIterator {
                defer { self.state += 1 }
                return self.state
            }
        }
    }
}

class LogisticsOptimizer {
    var sequence: AnySequence<Int>
    var inventory = 0
    var supply = 0

    init(sequence: AnySequence<Int>) {
        self.sequence = sequence
        self.supply = sequence.makeIterator().next() ?? 0
    }

    func updateInventory() {
        self.inventory += self.supply
        self.supply = sequence.makeIterator().next() ?? 0
    }

    func optimize() {
        while true {
            self.updateInventory()
            if self.inventory > 100 {
                self.supply = 0
            } else if self.inventory < 50 {
                self.supply = 50
            }
        }
    }
}

class SupplyChainSimulator {
    var sequenceGenerator = SequenceGenerator()
    var optimizer: LogisticsOptimizer

    init() {
        self.optimizer = LogisticsOptimizer(sequence: sequenceGenerator.generate())
    }

    func run() {
        while true {
            self.optimizer.optimize()
        }
    }
}

func main() {
    let simulator = SupplyChainSimulator()
    simulator.run()
}

main()