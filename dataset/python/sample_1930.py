import numpy as np

def update_grid(grid, precision):
    size = grid.shape[0]
    new_grid = np.zeros_like(grid)
    for i in range(1, size - 1):
        for j in range(1, size - 1):
            avg = np.mean(grid[i - 1:i + 2, j - 1:j + 2])
            new_grid[i, j] = np.round(avg, precision)
    return new_grid

def run_simulation(steps, precision):
    grid_size = 10
    grid = np.random.rand(grid_size, grid_size)
    for _ in range(steps):
        grid = update_grid(grid, precision)
    return grid
if __name__ == '__main__':
    steps = 50
    precision = 3
    result = run_simulation(steps, precision)
    print(result)