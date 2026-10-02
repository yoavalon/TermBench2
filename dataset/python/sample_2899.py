import numpy as np

def update_grid(grid):
    rows, cols = grid.shape
    new_grid = np.copy(grid)
    for i in range(rows):
        for j in range(cols):
            neighbors = np.sum(grid[max(0, i - 1):min(rows, i + 2), max(0, j - 1):min(cols, j + 2)]) - grid[i, j]
            if grid[i, j] == 1 and (neighbors < 2 or neighbors > 3):
                new_grid[i, j] = 0
            elif grid[i, j] == 0 and neighbors == 3:
                new_grid[i, j] = 1
    return new_grid

def simulate():
    grid = np.random.choice([0, 1], size=(10, 10))
    while True:
        grid = update_grid(grid)
        print(grid)
        if np.all(grid == 0):
            break
simulate()