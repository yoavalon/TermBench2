def cellular_automata():
    grid = [[0 for _ in range(10)] for _ in range(10)]
    while True:
        for i in range(1, 9):
            for j in range(1, 9):
                grid[i][j] = (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]) % 2
        for i in range(10):
            grid[i][0] = grid[i][9]
            grid[i][9] = grid[i][0]
            grid[0][i] = grid[9][i]
            grid[9][i] = grid[0][i]
cellular_automata()