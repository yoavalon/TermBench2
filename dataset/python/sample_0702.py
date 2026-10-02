def update_grid(grid, size):
    new_grid = [[0] * size for _ in range(size)]
    for i in range(size):
        for j in range(size):
            neighbors = sum((grid[x][y] for x in range(max(0, i - 1), min(size, i + 2)) for y in range(max(0, j - 1), min(size, j + 2)) if (x, y) != (i, j)))
            new_grid[i][j] = 1 if neighbors == 3 else grid[i][j] if neighbors == 2 else 0
    return new_grid

def simulate(size, steps):
    grid = [[0 if i % 2 else 1 for i in range(size)] for j in range(size)]
    for _ in range(steps):
        grid = update_grid(grid, size)
    return grid

def main():
    size = 5
    steps = 10
    result = simulate(size, steps)
    for row in result:
        print(' '.join(map(str, row)))
main()