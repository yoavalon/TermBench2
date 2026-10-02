class StateSimulator {
    var state: Int
    var rules: [(String, RuleApplier)]

    init(initial_state: Int, transition_rules: [(String, RuleApplier)]) {
        self.state = initial_state
        self.rules = transition_rules
    }

    func apply_rules() -> Int {
        var new_state = self.state
        for rule in self.rules {
            if rule.0.contains(String(self.state)) {
                new_state = rule.1(self.state)
                break
            }
        }
        return new_state
    }

    func simulate(steps: Int) {
        for _ in 0..<steps {
            self.state = self.apply_rules()
        }
    }
}

class RuleApplier {
    let condition: (Int) -> Bool
    let action: (Int) -> Int

    init(condition: @escaping (Int) -> Bool, action: @escaping (Int) -> Int) {
        self.condition = condition
        self.action = action
    }

    func callAsFunction(_ state: Int) -> Int {
        if self.condition(state) {
            return self.action(state)
        }
        return state
    }
}

func condition_a(state: Int) -> Bool {
    return state < 100
}

func action_a(state: Int) -> Int {
    return state + 10
}

func condition_b(state: Int) -> Bool {
    return state >= 100
}

func action_b(state: Int) -> Int {
    return state - 5
}

func main() {
    let initial_state = 50
    let rules = [("a", RuleApplier(condition: condition_a, action: action_a)), ("b", RuleApplier(condition: condition_b, action: action_b))]
    let simulator = StateSimulator(initial_state: initial_state, transition_rules: rules)
    simulator.simulate(steps: 20)
    print(simulator.state)
}

main()