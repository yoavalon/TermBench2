import numpy as np

def update_grid(grid):
    rows, cols = grid.shape
    new_grid = np.copy(grid)
    for i in range(rows):
        for j in range(cols):
            neighbors = grid[i, (j - 1) % cols] + grid[i, (j + 1) % cols] + grid[(i - 1) % rows, j] + grid[(i + 1) % rows, j] + grid[(i - 1) % rows, (j - 1) % cols] + grid[(i - 1) % rows, (j + 1) % cols] + grid[(i + 1) % rows, (j - 1) % cols] + grid[(i + 1) % rows, (j + 1) % cols]
            if grid[i, j] == 1:
                if neighbors < 2 or neighbors > 3:
                    new_grid[i, j] = 0
            elif neighbors == 3:
                new_grid[i, j] = 1
    return new_grid

def main():
    grid_size = 10
    grid = np.random.choice([0, 1], size=(grid_size, grid_size))
    while True:
        grid = update_grid(grid)
        print(grid)
        print('-' * 20)

main()