import numpy as np

def update_grid(grid, size):
    new_grid = np.zeros_like(grid)
    for i in range(1, size - 1):
        for j in range(1, size - 1):
            neighbors = grid[i - 1:i + 2, j - 1:j + 2].flatten()
            neighbors_sum = np.sum(neighbors) - grid[i, j]
            if grid[i, j] == 0 and neighbors_sum > 2:
                new_grid[i, j] = 1
            elif grid[i, j] == 1 and (neighbors_sum < 2 or neighbors_sum > 3):
                new_grid[i, j] = 0
            else:
                new_grid[i, j] = grid[i, j]
    return new_grid

def main():
    size = 50
    grid = np.zeros((size, size))
    grid[size // 2, size // 2] = 1
    while True:
        grid = update_grid(grid, size)

main()