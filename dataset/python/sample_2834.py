import numpy as np

def update_state(grid):
    rows, cols = grid.shape
    new_grid = np.copy(grid)
    for i in range(rows):
        for j in range(cols):
            neighbors = np.sum(grid[i - 1:i + 2, j - 1:j + 2]) - grid[i, j]
            if grid[i, j] == 1:
                if neighbors < 2 or neighbors > 3:
                    new_grid[i, j] = 0
            elif neighbors == 3:
                new_grid[i, j] = 1
    return new_grid

def main():
    size = 100
    grid = np.random.randint(2, size=(size, size))
    while True:
        grid = update_state(grid)
main()