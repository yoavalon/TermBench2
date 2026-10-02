def update_grid(grid):
    size = len(grid)
    new_grid = [[0] * size for _ in range(size)]
    for i in range(size):
        for j in range(size):
            neighbors = [grid[(i - 1) % size][(j - 1) % size], grid[(i - 1) % size][j], grid[(i - 1) % size][(j + 1) % size], grid[i][(j - 1) % size], grid[i][(j + 1) % size], grid[(i + 1) % size][(j - 1) % size], grid[(i + 1) % size][j], grid[(i + 1) % size][(j + 1) % size]]
            live_neighbors = sum(neighbors)
            if grid[i][j]:
                new_grid[i][j] = 1 if live_neighbors in (2, 3) else 0
            else:
                new_grid[i][j] = 1 if live_neighbors == 3 else 0
    return new_grid

def main():
    import random
    size = 10
    grid = [[random.choice([0, 1]) for _ in range(size)] for _ in range(size)]
    while True:
        grid = update_grid(grid)
        for row in grid:
            print(' '.join((str(cell) for cell in row)))
        print()
main()