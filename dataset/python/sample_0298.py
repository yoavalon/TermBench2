import numpy as np

class AutomataGrid:

    def __init__(self, size, density):
        self.grid = np.random.choice([0, 1], size=(size, size), p=[1 - density, density])
        self.size = size

    def apply_rules(self):
        new_grid = np.copy(self.grid)
        for i in range(1, self.size - 1):
            for j in range(1, self.size - 1):
                neighbors = self.grid[i - 1:i + 2, j - 1:j + 2].sum() - self.grid[i, j]
                if self.grid[i, j] == 1 and (neighbors < 2 or neighbors > 3):
                    new_grid[i, j] = 0
                elif self.grid[i, j] == 0 and neighbors == 3:
                    new_grid[i, j] = 1
        self.grid = new_grid

    def set_boundary_conditions(self):
        self.grid[:, 0] = self.grid[:, -2]
        self.grid[:, -1] = self.grid[:, 1]
        self.grid[0, :] = self.grid[-2, :]
        self.grid[-1, :] = self.grid[1, :]

class Simulation:

    def __init__(self, grid, steps):
        self.grid = grid
        self.steps = steps

    def run(self):
        for _ in range(self.steps):
            self.grid.apply_rules()
            self.grid.set_boundary_conditions()

def main():
    size = 10
    density = 0.3
    steps = 50
    grid = AutomataGrid(size, density)
    simulation = Simulation(grid, steps)
    simulation.run()
if __name__ == '__main__':
    main()