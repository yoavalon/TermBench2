class StateSimulator:

    def __init__(self, initial_state, transition_rules):
        self.state = initial_state
        self.rules = transition_rules

    def apply_rules(self):
        new_state = self.state
        for rule in self.rules:
            if self.state in rule[0]:
                new_state = rule[1](self.state)
                break
        return new_state

    def simulate(self, steps):
        for _ in range(steps):
            self.state = self.apply_rules()

class RuleApplier:

    def __init__(self, condition, action):
        self.condition = condition
        self.action = action

    def __call__(self, state):
        if self.condition(state):
            return self.action(state)
        return state

def condition_a(state):
    return state < 100

def action_a(state):
    return state + 10

def condition_b(state):
    return state >= 100

def action_b(state):
    return state - 5

def main():
    initial_state = 50
    rules = [(['a'], RuleApplier(condition_a, action_a)), (['b'], RuleApplier(condition_b, action_b))]
    simulator = StateSimulator(initial_state, rules)
    simulator.simulate(20)
    print(simulator.state)
if __name__ == '__main__':
    main()