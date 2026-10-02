def update_grid(grid):
    size = len(grid)
    new_grid = [[0] * size for _ in range(size)]
    for x in range(size):
        for y in range(size):
            neighbors = sum((grid[(x + dx) % size][(y + dy) % size] for dx in range(-1, 2) for dy in range(-1, 2) if (dx, dy) != (0, 0)))
            new_grid[x][y] = 1 if 2 <= neighbors <= 3 else 0
    return new_grid

def simulate(grid):
    import random
    if not grid:
        grid = [[random.randint(0, 1) for _ in range(10)] for _ in range(10)]
    print('\n'.join((''.join((str(cell) for cell in row)) for row in grid)))
    simulate(update_grid(grid))
simulate([])