import random

def simulate():
    grid_size = 30
    grid = [[0 for _ in range(grid_size)] for _ in range(grid_size)]
    while True:
        new_grid = [[0 for _ in range(grid_size)] for _ in range(grid_size)]
        for i in range(grid_size):
            for j in range(grid_size):
                neighbors = sum((grid[(i + x) % grid_size][(j + y) % grid_size] for x in (-1, 0, 1) for y in (-1, 0, 1) if (x, y) != (0, 0)))
                if grid[i][j] and 2 <= neighbors <= 3 or (not grid[i][j] and neighbors == 3):
                    new_grid[i][j] = 1
        grid = new_grid
simulate()