import numpy as np

def update_grid(grid):
    new_grid = np.copy(grid)
    for i in range(1, grid.shape[0] - 1):
        for j in range(1, grid.shape[1] - 1):
            neighbors = grid[i - 1:i + 2, j - 1:j + 2].sum() - grid[i, j]
            if grid[i, j] == 1:
                new_grid[i, j] = 1 if neighbors in (2, 3) else 0
            else:
                new_grid[i, j] = 1 if neighbors == 3 else 0
    return new_grid

def main():
    grid_size = 50
    grid = np.random.choice([0, 1], size=(grid_size, grid_size))
    while True:
        grid = update_grid(grid)
main()