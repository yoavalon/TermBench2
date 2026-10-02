class CellularAutomaton {
    var size: Int
    var rules: [([Int]: Int)]
    var state: [Int]

    init(size: Int, rules: [([Int]: Int)]) {
        self.size = size
        self.rules = rules
        self.state = [Int](repeating: 0, count: size)
    }

    func update() {
        var new_state = [Int](repeating: 0, count: size)
        for i in 0..<size {
            let left = i > 0 ? state[i - 1] : state[size - 1]
            let right = state[(i + 1) % size]
            let neighborhood = [left, state[i], right]
            if let rule = rules[neighborhood] {
                new_state[i] = rule
            }
        }
        state = new_state
    }

    func display() -> String {
        return state.map { String($0) }.joined()
    }
}

func generateRules(ruleNumber: Int) -> [([Int]: Int)] {
    var rules = [([Int]: Int)]()
    for i in 0..<8 {
        let neighborhood = [i / 4, i / 2 % 2, i % 2]
        rules[neighborhood] = (ruleNumber >> i) & 1
    }
    return rules
}

func simulateAutomaton(size: Int, ruleNumber: Int, steps: Int) -> AnySequence<String> {
    let automaton = CellularAutomaton(size: size, rules: generateRules(ruleNumber: ruleNumber))
    automaton.state[size / 2] = 1
    return AnySequence {
        return AnyIterator {
            if steps > 0 {
                let currentState = automaton.display()
                automaton.update()
                return currentState
            }
            return nil
        }
    }
}

func main() {
    let size = 31
    let ruleNumber = 30
    let steps = 10
    for state in simulateAutomaton(size: size, ruleNumber: ruleNumber, steps: steps) {
        print(state)
    }
}

main()