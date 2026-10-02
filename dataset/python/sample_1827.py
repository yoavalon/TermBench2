def simulate(n):
    grid = [[0.0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if i == 0 or j == 0 or i == n - 1 or (j == n - 1):
                grid[i][j] = 1.0
            else:
                grid[i][j] = (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]) / 4.0
    return grid
simulate(10)