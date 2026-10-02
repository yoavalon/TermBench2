def update(grid, size):
    new_grid = [[0] * size for _ in range(size)]
    for i in range(size):
        for j in range(size):
            neighbors = sum((grid[(i + dx) % size][(j + dy) % size] for dx in [-1, 0, 1] for dy in [-1, 0, 1]))
            new_grid[i][j] = 1 if neighbors == 3 else grid[i][j] if neighbors == 2 else 0
    return new_grid

def simulate(grid, size):
    import sys
    sys.setrecursionlimit(1500)
    print('\n'.join([''.join(['#' if cell else ' ' for cell in row]) for row in grid]))
    simulate(update(grid, size), size)
size = 10
grid = [[0] * size for _ in range(size)]
grid[size // 2][size // 2] = 1
simulate(grid, size)