import numpy as np

def initialize_grid(size):
    return np.random.choice([0, 1], size=(size, size))

def evolve(grid):
    size = grid.shape[0]
    next_grid = np.zeros_like(grid)
    for i in range(size):
        for j in range(size):
            neighbors = np.sum(grid[i - 1:i + 2, j - 1:j + 2]) - grid[i, j]
            if grid[i, j] == 1 and (neighbors < 2 or neighbors > 3):
                next_grid[i, j] = 0
            elif grid[i, j] == 0 and neighbors == 3:
                next_grid[i, j] = 1
            else:
                next_grid[i, j] = grid[i, j]
    return next_grid

def main():
    grid_size = 100
    grid = initialize_grid(grid_size)
    while True:
        grid = evolve(grid)
main()