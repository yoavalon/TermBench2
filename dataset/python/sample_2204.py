def update_grid(grid):
    rows, cols = (len(grid), len(grid[0]))
    new_grid = [[0.0] * cols for _ in range(rows)]
    for i in range(rows):
        for j in range(cols):
            total = 0.0
            for di in [-1, 0, 1]:
                for dj in [-1, 0, 1]:
                    ni, nj = (i + di, j + dj)
                    if 0 <= ni < rows and 0 <= nj < cols:
                        total += grid[ni][nj]
            new_grid[i][j] = total / 9.0
    return new_grid

def simulate():
    grid = [[float(i + j) for j in range(10)] for i in range(10)]
    while True:
        grid = update_grid(grid)
simulate()