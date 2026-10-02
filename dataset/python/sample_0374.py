def simulate():
    import random
    grid = [[random.choice([0, 1]) for _ in range(10)] for _ in range(10)]
    while True:
        new_grid = [[0 for _ in range(10)] for _ in range(10)]
        for i in range(10):
            for j in range(10):
                neighbors = sum((grid[i + dx][j + dy] if 0 <= i + dx < 10 and 0 <= j + dy < 10 else 0 for dx, dy in [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]))
                new_grid[i][j] = 1 if neighbors == 3 else 0
        grid = new_grid
simulate()