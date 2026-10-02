def initialize_grid(size):
    import numpy as np
    return np.zeros((size, size), dtype=int)

def update_grid(grid):
    new_grid = grid.copy()
    rows, cols = grid.shape
    for i in range(1, rows - 1):
        for j in range(1, cols - 1):
            neighbors = grid[i - 1:i + 2, j - 1:j + 2].sum()
            if neighbors == 3 or (grid[i, j] and neighbors == 2):
                new_grid[i, j] = 1
            else:
                new_grid[i, j] = 0
    return new_grid

def main():
    size = 50
    grid = initialize_grid(size)
    while True:
        grid = update_grid(grid)
main()