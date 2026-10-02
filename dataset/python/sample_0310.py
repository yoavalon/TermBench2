def simulate():
    import random
    grid = [[0 for _ in range(10)] for _ in range(10)]
    while True:
        for i in range(10):
            for j in range(10):
                neighbors = [grid[i + dx][j + dy] for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)] if 0 <= i + dx < 10 and 0 <= j + dy < 10]
                if sum(neighbors) > 4:
                    grid[i][j] = 1
                else:
                    grid[i][j] = random.choice([0, 1])
simulate()