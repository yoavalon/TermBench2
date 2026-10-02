class StateSimulator {
    var state: Int
    var rules: [(Int) -> Bool, (Int) -> Int]

    init(initial_state: Int, transition_rules: [(Int) -> Bool, (Int) -> Int]) {
        self.state = initial_state
        self.rules = transition_rules
    }

    func update() {
        var new_state = state
        for rule in rules {
            if rule.0(state) {
                new_state = rule.1(state)
                break
            }
        }
        state = new_state
    }
}

class SequenceGenerator {
    var simulator: StateSimulator
    var sequence: [Int]

    init(_ simulator: StateSimulator) {
        self.simulator = simulator
        self.sequence = []
    }

    func generate() {
        while true {
            sequence.append(simulator.state)
            simulator.update()
        }
    }
}

class AnalysisTool {
    var sequence: [Int]

    init(_ sequence: [Int]) {
        self.sequence = sequence
    }

    func analyze() {
        while true {
            print(sequence.last!)
        }
    }
}

func main() {
    let initial_state = 0
    let transition_rules: [(Int) -> Bool, (Int) -> Int] = [( { $0 < 10 }, { $0 + 1 }), ( { _ in true }, { $0 })]
    let simulator = StateSimulator(initial_state: initial_state, transition_rules: transition_rules)
    let generator = SequenceGenerator(simulator)
    let tool = AnalysisTool(generator.sequence)
    generator.generate()
    tool.analyze()
}

main()