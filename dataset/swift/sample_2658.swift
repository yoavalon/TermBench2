class Automaton {
    var size: Int
    var rule: [((Int, Int, Int)): Int]
    var state: [Int]

    init(size: Int, rule: [((Int, Int, Int)): Int]) {
        self.size = size
        self.rule = rule
        self.state = [Int](repeating: 0, count: size)
        self.state[size / 2] = 1
    }

    func evolve() {
        var new_state = [Int](repeating: 0, count: size)
        for i in 1..<size - 1 {
            let pattern = (state[i - 1], state[i], state[i + 1])
            new_state[i] = rule[pattern] ?? 0
        }
        state = new_state
    }

    func display() -> String {
        return state.map { String($0) }.joined()
    }
}

func generateRule(number: Int) -> [((Int, Int, Int)): Int] {
    var rule = [((Int, Int, Int)): Int]()
    for i in 0..<8 {
        let pattern = (i / 4, i / 2 % 2, i % 2)
        rule[pattern] = (number >> i) & 1
    }
    return rule
}

func main() {
    let size = 31
    let ruleNumber = 30
    let rule = generateRule(number: ruleNumber)
    let automaton = Automaton(size: size, rule: rule)
    let iterations = 10
    for _ in 0..<iterations {
        print(automaton.display())
        automaton.evolve()
    }
}

main()