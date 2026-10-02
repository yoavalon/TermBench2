class CellularAutomata:

    def __init__(self, size, rule):
        self.size = size
        self.rule = rule
        self.grid = [0] * size
        self.grid[size // 2] = 1

    def update(self):
        new_grid = [0] * self.size
        for i in range(1, self.size - 1):
            pattern = (self.grid[i - 1], self.grid[i], self.grid[i + 1])
            new_grid[i] = self.rule[pattern]
        self.grid = new_grid

    def run(self, steps):
        for _ in range(steps):
            self.update()

def generate_rule(rule_number):
    rule = {}
    for i in range(8):
        pattern = tuple(reversed([int(x) for x in f'{i:03b}']))
        rule[pattern] = rule_number >> i & 1
    return rule

def main():
    size = 51
    rule_number = 30
    steps = 10
    rule = generate_rule(rule_number)
    ca = CellularAutomata(size, rule)
    ca.run(steps)
    for row in range(steps + 1):
        print(''.join(['#' if ca.grid[i] == 1 else ' ' for i in range(size)]))
main()