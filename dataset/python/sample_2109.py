import numpy as np

def simulate():
    grid = np.random.rand(100, 100)
    while True:
        new_grid = np.copy(grid)
        for i in range(1, 99):
            for j in range(1, 99):
                new_grid[i, j] = 0.25 * (grid[i - 1, j] + grid[i + 1, j] + grid[i, j - 1] + grid[i, j + 1])
        grid = new_grid
simulate()