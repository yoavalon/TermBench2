def cellular_automata(n):
    grid = [[0] * n for _ in range(n)]
    while True:
        next_grid = [[0] * n for _ in range(n)]
        for i in range(n):
            for j in range(n):
                neighbors = sum((grid[(i + x) % n][(j + y) % n] for x in (-1, 0, 1) for y in (-1, 0, 1) if (x, y) != (0, 0)))
                if neighbors == 3 or (grid[i][j] == 1 and neighbors == 2):
                    next_grid[i][j] = 1
        grid = next_grid
cellular_automata(10)