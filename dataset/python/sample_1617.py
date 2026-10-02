import numpy as np

def update_state(grid):
    new_grid = np.copy(grid)
    for i in range(1, grid.shape[0] - 1):
        for j in range(1, grid.shape[1] - 1):
            neighbors = np.sum(grid[i - 1:i + 2, j - 1:j + 2]) - grid[i, j]
            if grid[i, j] == 1 and (neighbors < 2 or neighbors > 3):
                new_grid[i, j] = 0
            elif grid[i, j] == 0 and neighbors == 3:
                new_grid[i, j] = 1
    return new_grid

def main():
    size = 50
    grid = np.random.randint(2, size=(size, size))
    while True:
        grid = update_state(grid)
main()