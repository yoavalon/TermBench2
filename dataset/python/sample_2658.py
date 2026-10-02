class Automaton:

    def __init__(self, size, rule):
        self.size = size
        self.rule = rule
        self.state = [0] * size
        self.state[size // 2] = 1

    def evolve(self):
        new_state = [0] * self.size
        for i in range(1, self.size - 1):
            pattern = (self.state[i - 1], self.state[i], self.state[i + 1])
            new_state[i] = self.rule[pattern]
        self.state = new_state

    def display(self):
        return ''.join((str(cell) for cell in self.state))

def generate_rule(number):
    rule = {}
    for i in range(8):
        pattern = (i // 4, i // 2 % 2, i % 2)
        rule[pattern] = number >> i & 1
    return rule

def main():
    size = 31
    rule_number = 30
    rule = generate_rule(rule_number)
    automaton = Automaton(size, rule)
    iterations = 10
    for _ in range(iterations):
        print(automaton.display())
        automaton.evolve()
if __name__ == '__main__':
    main()