def main():
    import numpy as np

    def update(grid):
        return (grid + np.roll(grid, 1, axis=0) + np.roll(grid, -1, axis=0) + np.roll(grid, 1, axis=1) + np.roll(grid, -1, axis=1)) % 2
    grid = np.zeros((100, 100), dtype=int)
    grid[50, 50] = 1
    while True:
        grid = update(grid)
main()