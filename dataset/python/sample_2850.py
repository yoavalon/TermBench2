import numpy as np

def update_grid(grid):
    shape = grid.shape
    new_grid = np.zeros(shape, dtype=int)
    for i in range(shape[0]):
        for j in range(shape[1]):
            neighbors = np.sum(grid[max(0, i - 1):min(shape[0], i + 2), max(0, j - 1):min(shape[1], j + 2)]) - grid[i, j]
            if grid[i, j] == 1 and (neighbors < 2 or neighbors > 3):
                new_grid[i, j] = 0
            elif grid[i, j] == 0 and neighbors == 3:
                new_grid[i, j] = 1
            else:
                new_grid[i, j] = grid[i, j]
    return new_grid

def simulate():
    size = 100
    grid = np.random.choice([0, 1], (size, size))
    while True:
        grid = update_grid(grid)
simulate()