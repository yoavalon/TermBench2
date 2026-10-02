class CellularAutomata:

    def __init__(self, size, rule):
        self.size = size
        self.rule = rule
        self.state = [0] * size
        self.state[size // 2] = 1

    def apply_rule(self, left, center, right):
        index = 4 * left + 2 * center + right
        return self.rule >> index & 1

    def next_generation(self):
        new_state = [0] * self.size
        for i in range(self.size):
            left = self.state[(i - 1) % self.size]
            center = self.state[i]
            right = self.state[(i + 1) % self.size]
            new_state[i] = self.apply_rule(left, center, right)
        self.state = new_state

    def run(self, steps):
        results = []
        for _ in range(steps):
            results.append(self.state.copy())
            self.next_generation()
        return results

def generate_sequence(size, rule, steps):
    ca = CellularAutomata(size, rule)
    return ca.run(steps)

def display_sequence(sequence):
    for row in sequence:
        print(''.join(('1' if cell else '0' for cell in row)))

def main():
    size = 31
    rule = 30
    steps = 10
    sequence = generate_sequence(size, rule, steps)
    display_sequence(sequence)
main()