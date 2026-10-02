class SequenceGenerator {
    var current: Int
    var end: Int
    var step: Int

    init(start: Int, end: Int, step: Int) {
        self.current = start
        self.end = end
        self.step = step
    }

    func generate() -> [Int] {
        var sequence = [Int]()
        while current <= end {
            sequence.append(current)
            current += step
        }
        return sequence
    }
}

class LogisticsOptimizer {
    var demand: Int
    var supply: Int

    init(demand: Int, supply: Int) {
        self.demand = demand
        self.supply = supply
    }

    func calculateDeficit() -> Int {
        return max(0, demand - supply)
    }

    func optimize() -> Int {
        let deficit = calculateDeficit()
        if deficit > 0 {
            return supply + deficit
        }
        return supply
    }
}

func main() {
    let demandSequence = SequenceGenerator(start: 100, end: 200, step: 10).generate()
    let supplySequence = SequenceGenerator(start: 120, end: 220, step: 15).generate()
    var optimizedSupplies = [Int]()
    for (d, s) in zip(demandSequence, supplySequence) {
        let optimizer = LogisticsOptimizer(demand: d, supply: s)
        optimizedSupplies.append(optimizer.optimize())
    }
    print(optimizedSupplies)
}

main()