def fluid_dynamics(grid):
    size = len(grid)
    next_grid = [[0] * size for _ in range(size)]
    for i in range(size):
        for j in range(size):
            neighbors = sum((grid[x][y] for x in range(max(0, i - 1), min(size, i + 2)) for y in range(max(0, j - 1), min(size, j + 2))))
            next_grid[i][j] = 1 if neighbors > 4 else 0
    return fluid_dynamics(next_grid)
grid = [[0] * 10 for _ in range(10)]
grid[5][5] = 1
fluid_dynamics(grid)