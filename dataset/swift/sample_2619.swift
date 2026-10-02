class SequenceGenerator {
    var current: Int
    var stop: Int
    var step: Int

    init(start: Int, stop: Int, step: Int) {
        self.current = start
        self.stop = stop
        self.step = step
    }

    func generate() -> AnySequence<Int> {
        return AnySequence {
            return AnyIterator {
                guard self.current < self.stop else { return nil }
                let value = self.current
                self.current += self.step
                return value
            }
        }
    }
}

class ThermodynamicSimulator {
    var sequence: SequenceGenerator
    var temperature: Double = 300.0

    init(sequence: SequenceGenerator) {
        self.sequence = sequence
    }

    func simulate() -> AnySequence<Double> {
        return AnySequence {
            return AnyIterator {
                guard let value = self.sequence.generate().makeIterator().next() else { return nil }
                self.temperature += Double(value) * 0.1
                return self.temperature
            }
        }
    }
}

class DataCollector {
    var simulator: ThermodynamicSimulator
    var data: [Double] = []

    init(simulator: ThermodynamicSimulator) {
        self.simulator = simulator
    }

    func collect() -> [Double] {
        for temp in self.simulator.simulate() {
            self.data.append(temp)
        }
        return self.data
    }
}

func main() {
    let start = 0
    let stop = 100
    let step = 5
    let sequence = SequenceGenerator(start: start, stop: stop, step: step)
    let simulator = ThermodynamicSimulator(sequence: sequence)
    let collector = DataCollector(simulator: simulator)
    let result = collector.collect()
    print(result)
}

main()