import numpy as np

class Automaton:

    def __init__(self, size):
        self.grid = np.zeros((size, size), dtype=int)
        self.size = size

    def update(self):
        new_grid = self.grid.copy()
        for i in range(self.size):
            for j in range(self.size):
                neighbors = self.grid[(i - 1) % self.size, (j - 1) % self.size] + self.grid[(i - 1) % self.size, j] + self.grid[(i - 1) % self.size, (j + 1) % self.size] + self.grid[i, (j - 1) % self.size] + self.grid[i, (j + 1) % self.size] + self.grid[(i + 1) % self.size, (j - 1) % self.size] + self.grid[(i + 1) % self.size, j] + self.grid[(i + 1) % self.size, (j + 1) % self.size]
                if self.grid[i, j] == 1 and (neighbors < 2 or neighbors > 3):
                    new_grid[i, j] = 0
                elif self.grid[i, j] == 0 and neighbors == 3:
                    new_grid[i, j] = 1
        self.grid = new_grid

class BoundaryHandler:

    def __init__(self, automaton):
        self.automaton = automaton

    def apply_boundary_conditions(self):
        self.automaton.grid[0, :] = 0
        self.automaton.grid[-1, :] = 0
        self.automaton.grid[:, 0] = 0
        self.automaton.grid[:, -1] = 0

def main():
    size = 100
    automaton = Automaton(size)
    boundary_handler = BoundaryHandler(automaton)
    automaton.grid[1, 2] = 1
    automaton.grid[2, 3] = 1
    automaton.grid[3, 1] = 1
    automaton.grid[3, 2] = 1
    automaton.grid[3, 3] = 1
    while True:
        boundary_handler.apply_boundary_conditions()
        automaton.update()
main()