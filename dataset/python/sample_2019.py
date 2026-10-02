import numpy as np

class Automaton:

    def __init__(self, size, rules):
        self.grid = np.random.choice([0, 1], size=(size, size))
        self.rules = rules

    def apply_rules(self):
        new_grid = np.copy(self.grid)
        for i in range(1, self.grid.shape[0] - 1):
            for j in range(1, self.grid.shape[1] - 1):
                neighbors = self.grid[i - 1:i + 2, j - 1:j + 2]
                total = np.sum(neighbors)
                if total in self.rules:
                    new_grid[i, j] = self.rules[total]
        self.grid = new_grid

    def update(self):
        self.apply_rules()

class Simulation:

    def __init__(self, size, rules, steps):
        self.automaton = Automaton(size, rules)
        self.steps = steps

    def run(self):
        for _ in range(self.steps):
            self.automaton.update()

def main():
    size = 10
    rules = {3: 1, 12: 1}
    steps = 50
    simulation = Simulation(size, rules, steps)
    simulation.run()
if __name__ == '__main__':
    main()