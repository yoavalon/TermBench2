import numpy as np

def init_grid(size):
    grid = np.zeros((size, size), dtype=int)
    grid[size // 2, size // 2] = 1
    return grid

def update_grid(grid):
    new_grid = grid.copy()
    for i in range(grid.shape[0]):
        for j in range(grid.shape[1]):
            neighbors = np.sum(grid[max(0, i - 1):min(grid.shape[0], i + 2), max(0, j - 1):min(grid.shape[1], j + 2)]) - grid[i, j]
            if grid[i, j] == 1 and (neighbors < 2 or neighbors > 3):
                new_grid[i, j] = 0
            elif grid[i, j] == 0 and neighbors == 3:
                new_grid[i, j] = 1
    return new_grid

def main():
    size = 10
    grid = init_grid(size)
    steps = 50
    for _ in range(steps):
        grid = update_grid(grid)
    print(grid)
main()