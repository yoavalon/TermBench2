def cellular_automata(size, steps):
    grid = [[0 for _ in range(size)] for _ in range(size)]
    for _ in range(steps):
        new_grid = [[0 for _ in range(size)] for _ in range(size)]
        for i in range(size):
            for j in range(size):
                neighbors = sum((grid[(i + dx) % size][(j + dy) % size] for dx in (-1, 0, 1) for dy in (-1, 0, 1))) - grid[i][j]
                new_grid[i][j] = 1 if neighbors == 3 or (grid[i][j] and neighbors == 2) else 0
        grid = new_grid
    return grid
cellular_automata(10, 5)