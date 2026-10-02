import numpy as np

def initialize_grid(size):
    grid = np.zeros((size, size), dtype=int)
    grid[size // 2, size // 2] = 1
    return grid

def apply_boundary_conditions(grid):
    size = grid.shape[0]
    for i in range(size):
        grid[0, i] = 0
        grid[size - 1, i] = 0
        grid[i, 0] = 0
        grid[i, size - 1] = 0

def update_grid(grid):
    new_grid = np.copy(grid)
    size = grid.shape[0]
    for i in range(1, size - 1):
        for j in range(1, size - 1):
            neighbors = grid[i - 1:i + 2, j - 1:j + 2].sum() - grid[i, j]
            if grid[i, j] == 1:
                if neighbors < 2 or neighbors > 3:
                    new_grid[i, j] = 0
            elif neighbors == 3:
                new_grid[i, j] = 1
    return new_grid

def simulate(steps):
    size = 50
    grid = initialize_grid(size)
    apply_boundary_conditions(grid)
    for _ in range(steps):
        grid = update_grid(grid)
        apply_boundary_conditions(grid)
    return grid

def main():
    steps = 100
    result = simulate(steps)
    print(result)
main()