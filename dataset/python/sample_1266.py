def cellular_automata(n, m, steps):
    import numpy as np
    grid = np.random.choice([0, 1], size=(n, m))
    for _ in range(steps):
        new_grid = grid.copy()
        for i in range(n):
            for j in range(m):
                neighbors = np.sum(grid[max(i - 1, 0):min(i + 2, n), max(j - 1, 0):min(j + 2, m)]) - grid[i, j]
                new_grid[i, j] = 1 if neighbors == 3 or (neighbors == 2 and grid[i, j]) else 0
        grid = new_grid
    return grid
cellular_automata(10, 10, 5)