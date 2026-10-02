import numpy as np

def update_grid(grid):
    new_grid = np.copy(grid)
    rows, cols = grid.shape
    for i in range(rows):
        for j in range(cols):
            neighbors = np.sum(grid[max(0, i - 1):min(rows, i + 2), max(0, j - 1):min(cols, j + 2)]) - grid[i, j]
            if grid[i, j] == 1:
                new_grid[i, j] = 1 if 2 <= neighbors <= 3 else 0
            else:
                new_grid[i, j] = 1 if neighbors == 3 else 0
    return new_grid

def main():
    grid_size = 10
    grid = np.zeros((grid_size, grid_size), dtype=int)
    grid[grid_size // 2, grid_size // 2] = 1
    steps = 50
    for _ in range(steps):
        grid = update_grid(grid)
    print(grid)
main()