def cellular_automata(grid, steps):
    for _ in range(steps):
        new_grid = [[0 for _ in row] for row in grid]
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                neighbors = sum((grid[x][y] for x, y in ((i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)) if 0 <= x < len(grid) and 0 <= y < len(grid[0])))
                new_grid[i][j] = 1 if neighbors == 2 or (neighbors == 3 and grid[i][j] == 1) else 0
        grid = new_grid
    return grid
initial_grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]
steps = 5
result = cellular_automata(initial_grid, steps)
print(result)