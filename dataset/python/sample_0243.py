import numpy as np

class Automata:

    def __init__(self, size, boundary_type):
        self.grid = np.zeros((size, size), dtype=int)
        self.boundary_type = boundary_type
        self.size = size

    def apply_boundary_conditions(self):
        if self.boundary_type == 'fixed':
            self.grid[:, 0] = 1
            self.grid[:, -1] = 1
            self.grid[0, :] = 1
            self.grid[-1, :] = 1
        elif self.boundary_type == 'periodic':
            self.grid[:, 0] = self.grid[:, -2]
            self.grid[:, -1] = self.grid[:, 1]
            self.grid[0, :] = self.grid[-2, :]
            self.grid[-1, :] = self.grid[1, :]

    def update_grid(self):
        new_grid = self.grid.copy()
        for i in range(1, self.size - 1):
            for j in range(1, self.size - 1):
                neighbors = self.grid[i - 1:i + 2, j - 1:j + 2].sum() - self.grid[i, j]
                if self.grid[i, j] == 1:
                    if neighbors < 2 or neighbors > 3:
                        new_grid[i, j] = 0
                elif neighbors == 3:
                    new_grid[i, j] = 1
        self.grid = new_grid

class Simulation:

    def __init__(self, automata, steps):
        self.automata = automata
        self.steps = steps

    def run(self):
        for _ in range(self.steps):
            self.automata.apply_boundary_conditions()
            self.automata.update_grid()

def main():
    size = 10
    boundary_type = 'fixed'
    steps = 50
    automata = Automata(size, boundary_type)
    simulation = Simulation(automata, steps)
    simulation.run()
if __name__ == '__main__':
    main()