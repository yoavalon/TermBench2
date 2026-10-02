class SequenceGenerator {
    var n: Int
    var current: Int

    init(n: Int) {
        self.n = n
        self.current = 0
    }

    func generate_sequence() -> [Int] {
        var sequence: [Int] = []
        while current < n {
            sequence.append(current)
            current += 1
        }
        return sequence
    }
}

class StateSimulator {
    var sequence: [Int]
    var index: Int

    init(sequence: [Int]) {
        self.sequence = sequence
        self.index = 0
    }

    func simulate_state() -> Int? {
        if index < sequence.count {
            let state = sequence[index]
            index += 1
            return state
        }
        return nil
    }
}

func main() {
    let n = 10
    let generator = SequenceGenerator(n: n)
    let sequence = generator.generate_sequence()
    let simulator = StateSimulator(sequence: sequence)
    while true {
        if let state = simulator.simulate_state() {
            print("Simulating state: \(state)")
        } else {
            break
        }
    }
}

main()