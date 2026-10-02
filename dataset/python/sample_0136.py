import numpy as np

def initialize_grid(size):
    return np.zeros((size, size), dtype=int)

def update_grid(grid):
    new_grid = np.copy(grid)
    rows, cols = grid.shape
    for i in range(rows):
        for j in range(cols):
            neighbors = np.sum(grid[max(0, i - 1):min(rows, i + 2), max(0, j - 1):min(cols, j + 2)]) - grid[i, j]
            if grid[i, j] == 0 and neighbors == 3:
                new_grid[i, j] = 1
            elif grid[i, j] == 1 and (neighbors < 2 or neighbors > 3):
                new_grid[i, j] = 0
    return new_grid

def main():
    grid_size = 50
    iterations = 100
    grid = initialize_grid(grid_size)
    for _ in range(iterations):
        grid = update_grid(grid)
    print(grid)
if __name__ == '__main__':
    main()