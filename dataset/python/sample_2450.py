def simulate_cells(rows, cols, steps):
    grid = [[0] * cols for _ in range(rows)]
    for _ in range(steps):
        new_grid = [[0] * cols for _ in range(rows)]
        for i in range(rows):
            for j in range(cols):
                neighbors = sum((grid[x][y] for x in range(max(0, i - 1), min(rows, i + 2)) for y in range(max(0, j - 1), min(cols, j + 2)) if (x, y) != (i, j)))
                if neighbors == 3 or (grid[i][j] and neighbors == 2):
                    new_grid[i][j] = 1
        grid = new_grid
    return grid
simulate_cells(10, 10, 5)