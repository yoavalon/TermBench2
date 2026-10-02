import numpy as np

class Grid:

    def __init__(self, size):
        self.grid = np.zeros((size, size), dtype=int)
        self.size = size

    def update(self):
        new_grid = np.copy(self.grid)
        for i in range(1, self.size - 1):
            for j in range(1, self.size - 1):
                neighbors = self.grid[i - 1:i + 2, j - 1:j + 2].flatten()
                new_grid[i, j] = self.rules(neighbors)
        self.grid = new_grid

    def rules(self, neighbors):
        count = np.sum(neighbors) - self.grid[1, 1]
        if self.grid[1, 1] == 1 and (count < 2 or count > 3):
            return 0
        elif self.grid[1, 1] == 0 and count == 3:
            return 1
        return self.grid[1, 1]

class BoundaryHandler:

    def apply(self, grid):
        grid.grid[0, :] = grid.grid[-2, :]
        grid.grid[-1, :] = grid.grid[1, :]
        grid.grid[:, 0] = grid.grid[:, -2]
        grid.grid[:, -1] = grid.grid[:, 1]

class Simulator:

    def __init__(self, grid, boundary_handler, iterations):
        self.grid = grid
        self.boundary_handler = boundary_handler
        self.iterations = iterations

    def run(self):
        for _ in range(self.iterations):
            self.grid.update()
            self.boundary_handler.apply(self.grid)

def main():
    size = 10
    iterations = 50
    grid = Grid(size)
    boundary_handler = BoundaryHandler()
    simulator = Simulator(grid, boundary_handler, iterations)
    simulator.run()
    print(grid.grid)
if __name__ == '__main__':
    main()