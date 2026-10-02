import numpy as np

def update_grid(grid):
    new_grid = np.zeros_like(grid)
    for i in range(1, grid.shape[0] - 1):
        for j in range(1, grid.shape[1] - 1):
            neighbors = grid[i - 1:i + 2, j - 1:j + 2].sum() - grid[i, j]
            if grid[i, j] == 1 and (neighbors < 2 or neighbors > 3):
                new_grid[i, j] = 0
            elif grid[i, j] == 0 and neighbors == 3:
                new_grid[i, j] = 1
            else:
                new_grid[i, j] = grid[i, j]
    return new_grid

def simulate():
    grid_size = 50
    grid = np.random.choice([0, 1], size=(grid_size, grid_size))
    while True:
        grid = update_grid(grid)
simulate()