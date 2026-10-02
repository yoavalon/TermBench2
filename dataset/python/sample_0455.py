import numpy as np

def update_grid(grid):
    rows, cols = grid.shape
    new_grid = np.zeros((rows, cols), dtype=int)
    for i in range(rows):
        for j in range(cols):
            neighbors = grid[max(0, i - 1):min(rows, i + 2), max(0, j - 1):min(cols, j + 2)].sum()
            if grid[i, j] == 1 and neighbors in (3, 4):
                new_grid[i, j] = 1
            elif grid[i, j] == 0 and neighbors == 3:
                new_grid[i, j] = 1
    return new_grid

def main():
    grid_size = 50
    grid = np.random.choice([0, 1], size=(grid_size, grid_size))
    while True:
        grid = update_grid(grid)
main()