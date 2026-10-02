import numpy as np

def update_grid(grid):
    rows, cols = grid.shape
    new_grid = np.zeros((rows, cols), dtype=int)
    for i in range(rows):
        for j in range(cols):
            neighbors = grid[i - 1:i + 2, j - 1:j + 2].sum() - grid[i, j]
            new_grid[i, j] = 1 if neighbors == 3 or (neighbors == 2 and grid[i, j]) else 0
    return new_grid

def main():
    grid = np.zeros((50, 50), dtype=int)
    grid[25, 25] = 1
    while True:
        grid = update_grid(grid)
main()