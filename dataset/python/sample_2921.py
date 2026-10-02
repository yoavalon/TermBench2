class Automaton:

    def __init__(self, grid_size, rule):
        self.grid = [[0 for _ in range(grid_size)] for _ in range(grid_size)]
        self.rule = rule
        self.grid_size = grid_size

    def set_initial_state(self, state):
        for i in range(self.grid_size):
            for j in range(self.grid_size):
                self.grid[i][j] = state[i][j]

    def update(self):
        new_grid = [[0 for _ in range(self.grid_size)] for _ in range(self.grid_size)]
        for i in range(self.grid_size):
            for j in range(self.grid_size):
                neighbors = (self.grid[(i - 1) % self.grid_size][(j - 1) % self.grid_size], self.grid[(i - 1) % self.grid_size][j], self.grid[(i - 1) % self.grid_size][(j + 1) % self.grid_size], self.grid[i][(j - 1) % self.grid_size], self.grid[i][(j + 1) % self.grid_size], self.grid[(i + 1) % self.grid_size][(j - 1) % self.grid_size], self.grid[(i + 1) % self.grid_size][j], self.grid[(i + 1) % self.grid_size][(j + 1) % self.grid_size])
                new_grid[i][j] = self.apply_rule(neighbors)
        self.grid = new_grid

    def apply_rule(self, neighbors):
        return self.rule(sum(neighbors))

class Rule:

    def __init__(self, threshold):
        self.threshold = threshold

    def __call__(self, count):
        return 1 if count > self.threshold else 0

def main():
    grid_size = 10
    initial_state = [[0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 1, 0, 0, 0, 0, 0], [0, 0, 0, 1, 1, 1, 0, 0, 0, 0], [0, 0, 0, 0, 1, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]
    rule = Rule(3)
    automaton = Automaton(grid_size, rule)
    automaton.set_initial_state(initial_state)
    while True:
        automaton.update()
main()