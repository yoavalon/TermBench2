import numpy as np

def update_grid(grid):
    rows, cols = grid.shape
    new_grid = np.copy(grid)
    for i in range(rows):
        for j in range(cols):
            neighbors = grid[i - 1:i + 2, j - 1:j + 2]
            alive_neighbors = np.sum(neighbors) - grid[i, j]
            if grid[i, j] == 1 and (alive_neighbors < 2 or alive_neighbors > 3):
                new_grid[i, j] = 0
            elif grid[i, j] == 0 and alive_neighbors == 3:
                new_grid[i, j] = 1
    return new_grid

def simulate(grid_size):
    grid = np.random.choice([0, 1], size=(grid_size, grid_size))
    while True:
        grid = update_grid(grid)
        print(grid)
simulate(10)