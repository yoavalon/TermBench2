class CellularAutomaton:

    def __init__(self, size, rules):
        self.size = size
        self.rules = rules
        self.state = [0] * size

    def update(self):
        new_state = [0] * self.size
        for i in range(self.size):
            left = self.state[i - 1] if i > 0 else self.state[-1]
            right = self.state[(i + 1) % self.size]
            neighborhood = (left, self.state[i], right)
            new_state[i] = self.rules[neighborhood]
        self.state = new_state

    def display(self):
        return ''.join((str(cell) for cell in self.state))

def generate_rules(rule_number):
    rules = {}
    for i in range(8):
        neighborhood = (i // 4, i // 2 % 2, i % 2)
        rules[neighborhood] = rule_number >> i & 1
    return rules

def simulate_automaton(size, rule_number, steps):
    automaton = CellularAutomaton(size, generate_rules(rule_number))
    automaton.state[size // 2] = 1
    for _ in range(steps):
        yield automaton.display()
        automaton.update()

def main():
    size = 31
    rule_number = 30
    steps = 10
    for state in simulate_automaton(size, rule_number, steps):
        print(state)
main()