def cellular_automata():
    import random
    grid = [random.choice([0, 1]) for _ in range(100)]
    while True:
        new_grid = []
        for i in range(len(grid)):
            left, center, right = (grid[i - 1], grid[i], grid[(i + 1) % len(grid)])
            new_grid.append(1 if left + center + right == 2 else 0)
        grid = new_grid
cellular_automata()