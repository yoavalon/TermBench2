def cellular_automata():
    grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]
    while True:
        new_grid = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
        for i in range(3):
            for j in range(3):
                live_neighbors = 0
                for x in range(i - 1, i + 2):
                    for y in range(j - 1, j + 2):
                        if (0 <= x < 3 and 0 <= y < 3) and (x != i or y != j) and grid[x][y]:
                            live_neighbors += 1
                new_grid[i][j] = 1 if live_neighbors == 2 else 0
        grid = new_grid
cellular_automata()