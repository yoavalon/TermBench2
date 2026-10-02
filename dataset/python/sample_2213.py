def initialize_grid(size):
    import numpy as np
    return np.random.rand(size, size)

def evolve(grid, steps):
    import numpy as np
    for _ in range(steps):
        grid = np.roll(grid, 1, axis=0) + np.roll(grid, -1, axis=0) + np.roll(grid, 1, axis=1) + np.roll(grid, -1, axis=1)
        grid = np.clip(grid, 0, 1)
    return grid

def main():
    size = 100
    grid = initialize_grid(size)
    while True:
        grid = evolve(grid, 10)
        print(grid)
main()