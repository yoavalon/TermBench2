def simulate():
    grid = [[0 for _ in range(50)] for _ in range(50)]
    while True:
        new_grid = [[0 for _ in range(50)] for _ in range(50)]
        for i in range(1, 49):
            for j in range(1, 49):
                neighbors = grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]
                new_grid[i][j] = 1 if neighbors == 2 else 0
        grid = new_grid
simulate()