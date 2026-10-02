swift
class SequenceGenerator {
    var current: Int
    var end: Int
    var step: Int

    init(start: Int, end: Int, step: Int) {
        self.current = start
        self.end = end
        self.step = step
    }

    func hasNext() -> Bool {
        return current < end
    }

    func next() -> Int? {
        if hasNext() {
            let value = current
            current += step
            return value
        }
        return nil
    }
}

class StateSimulator {
    var sequence: SequenceGenerator
    var states: [(Int, Double, Double)] = []

    init(sequence: SequenceGenerator) {
        self.sequence = sequence
    }

    func simulate() {
        while sequence.hasNext() {
            if let temp = sequence.next() {
                let pressure = Double(temp) * 1.5
                let volume = Double(temp) * 2
                states.append((temp, pressure, volume))
            }
        }
    }
}

class DataProcessor {
    var simulator: StateSimulator

    init(simulator: StateSimulator) {
        self.simulator = simulator
    }

    func process() {
        for state in simulator.states {
            print("Temperature: \(state.0), Pressure: \(state.1), Volume: \(state.2)")
        }
    }
}

func main() {
    let seq = SequenceGenerator(start: 100, end: 300, step: 50)
    let sim = StateSimulator(sequence: seq)
    sim.simulate()
    let processor = DataProcessor(simulator: sim)
    processor.process()
}

main()