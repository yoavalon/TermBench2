def simulate_flow(n):
    grid = [[0.0] * n for _ in range(n)]
    while True:
        new_grid = [[0.0] * n for _ in range(n)]
        for i in range(n):
            for j in range(n):
                new_grid[i][j] = (grid[i][(j - 1) % n] + grid[i][(j + 1) % n] + grid[(i - 1) % n][j] + grid[(i + 1) % n][j]) / 4
        grid = new_grid
simulate_flow(10)