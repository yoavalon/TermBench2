import numpy as np

def update_grid(grid):
    new_grid = np.copy(grid)
    for i in range(1, grid.shape[0] - 1):
        for j in range(1, grid.shape[1] - 1):
            neighbors = np.sum(grid[i - 1:i + 2, j - 1:j + 2]) - grid[i, j]
            if grid[i, j] and (neighbors < 2 or neighbors > 3):
                new_grid[i, j] = 0
            elif not grid[i, j] and neighbors == 3:
                new_grid[i, j] = 1
    return new_grid

def simulate(grid, steps):
    for _ in range(steps):
        grid = update_grid(grid)
    return grid

def main():
    size = 50
    grid = np.zeros((size, size), dtype=int)
    grid[20:25, 20:25] = np.random.randint(2, size=(5, 5))
    final_grid = simulate(grid, 100)
    print(final_grid)
main()