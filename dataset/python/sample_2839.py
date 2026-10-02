import numpy as np

def update_grid(grid):
    rows, cols = grid.shape
    new_grid = np.zeros((rows, cols), dtype=int)
    for i in range(rows):
        for j in range(cols):
            neighbors = np.sum(grid[max(i - 1, 0):min(i + 2, rows), max(j - 1, 0):min(j + 2, cols)]) - grid[i, j]
            if grid[i, j] == 1 and (neighbors < 2 or neighbors > 3):
                new_grid[i, j] = 0
            elif grid[i, j] == 0 and neighbors == 3:
                new_grid[i, j] = 1
            else:
                new_grid[i, j] = grid[i, j]
    return new_grid

def main():
    size = 10
    grid = np.random.choice([0, 1], size=(size, size))
    while True:
        grid = update_grid(grid)
main()