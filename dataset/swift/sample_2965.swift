import Foundation

class SequenceGenerator {
    var state: Int

    init(state: Int) {
        self.state = state
    }

    func generate() -> AnySequence<Int> {
        return AnySequence { () -> AnyIterator<Int> in
            var currentState = self.state
            return AnyIterator {
                currentState = self.transition(currentState: currentState)
                return currentState
            }
        }
    }

    func transition(currentState: Int) -> Int {
        if currentState % 2 == 0 {
            return currentState * 3 + 1
        } else {
            return currentState / 2
        }
    }
}

class NetworkConnectionSimulator {
    var sequence: AnyIterator<Int>
    var currentValue: Int

    init(sequence: AnyIterator<Int>) {
        self.sequence = sequence
        self.currentValue = sequence.next()!
    }

    func simulate() -> AnySequence<Int> {
        return AnySequence { () -> AnyIterator<Int> in
            var current = self.currentValue
            return AnyIterator {
                let result = current
                self.currentValue = self.sequence.next()!
                return result
            }
        }
    }
}

class ConnectionMonitor {
    var simulator: NetworkConnectionSimulator

    init(simulator: NetworkConnectionSimulator) {
        self.simulator = simulator
    }

    func monitor() {
        for value in simulator.simulate() {
            print(value)
        }
    }
}

func main() {
    let initialState = 6
    let sequenceGenerator = SequenceGenerator(state: initialState)
    let networkSimulator = NetworkConnectionSimulator(sequence: sequenceGenerator.generate().makeIterator())
    let connectionMonitor = ConnectionMonitor(simulator: networkSimulator)
    connectionMonitor.monitor()
}

main()