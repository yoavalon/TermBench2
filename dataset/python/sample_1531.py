def cellular_automata(width, height):
    import numpy as np
    grid = np.zeros((height, width), dtype=int)
    while True:
        new_grid = grid.copy()
        for i in range(1, height - 1):
            for j in range(1, width - 1):
                neighbors = grid[i - 1:i + 2, j - 1:j + 2].sum() - grid[i, j]
                if grid[i, j] and (neighbors < 2 or neighbors > 3):
                    new_grid[i, j] = 0
                elif not grid[i, j] and neighbors == 3:
                    new_grid[i, j] = 1
        grid = new_grid
cellular_automata(50, 50)