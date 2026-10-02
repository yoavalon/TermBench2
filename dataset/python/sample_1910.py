import numpy as np

def update_grid(grid):
    rows, cols = grid.shape
    new_grid = np.zeros((rows, cols), dtype=np.float32)
    for i in range(1, rows - 1):
        for j in range(1, cols - 1):
            neighbors = grid[i - 1:i + 2, j - 1:j + 2]
            new_grid[i, j] = np.sum(neighbors) - grid[i, j]
    return new_grid

def simulate_flow(iterations):
    grid = np.random.rand(10, 10).astype(np.float32)
    for _ in range(iterations):
        grid = update_grid(grid)
    return grid

def main():
    result = simulate_flow(100)
    print(result)
main()