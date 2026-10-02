import numpy as np

class CellularAutomata:

    def __init__(self, size, rule):
        self.grid = np.zeros((size, size), dtype=np.float32)
        self.grid[size // 2, size // 2] = 1.0
        self.rule = rule

    def apply_rule(self, neighborhood):
        s = np.sum(neighborhood)
        if s == 3:
            return 1.0
        elif s == 2:
            return self.grid[neighborhood.shape[0] // 2, neighborhood.shape[1] // 2]
        else:
            return 0.0

    def update_grid(self):
        new_grid = np.zeros_like(self.grid)
        for i in range(1, self.grid.shape[0] - 1):
            for j in range(1, self.grid.shape[1] - 1):
                neighborhood = self.grid[i - 1:i + 2, j - 1:j + 2]
                new_grid[i, j] = self.apply_rule(neighborhood)
        self.grid = new_grid

class FluidSimulation:

    def __init__(self, size, rule):
        self.ca = CellularAutomata(size, rule)

    def simulate(self):
        while True:
            self.ca.update_grid()

def main():
    sim = FluidSimulation(50, 30)
    sim.simulate()
main()