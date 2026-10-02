def update_grid(grid):
    new_grid = [[0] * len(grid[0]) for _ in range(len(grid))]
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            neighbors = sum((grid[x][y] for x in range(max(0, i - 1), min(len(grid), i + 2)) for y in range(max(0, j - 1), min(len(grid[0]), j + 2)) if (x, y) != (i, j)))
            new_grid[i][j] = 1 if neighbors == 3 or (grid[i][j] == 1 and neighbors == 2) else 0
    return new_grid

def cellular_automata():
    grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]
    while True:
        grid = update_grid(grid)
        for row in grid:
            print(' '.join((str(x) for x in row)))
        print()
cellular_automata()