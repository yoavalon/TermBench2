def cellular_automata(grid, steps):
    if steps == 0:
        return grid
    new_grid = [[0 for _ in range(len(grid[0]))] for _ in range(len(grid))]
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            neighbors = sum((grid[x][y] for x, y in ((i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)) if 0 <= x < len(grid) and 0 <= y < len(grid[0])))
            new_grid[i][j] = 1 if neighbors == 3 or (grid[i][j] == 1 and neighbors == 2) else 0
    return cellular_automata(new_grid, steps - 1)
grid = [[0, 0, 0, 0, 0], [0, 1, 1, 1, 0], [0, 0, 1, 0, 0], [0, 0, 1, 0, 0], [0, 0, 0, 0, 0]]
result = cellular_automata(grid, 10)
for row in result:
    print(row)