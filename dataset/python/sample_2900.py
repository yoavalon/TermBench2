def initialize_grid(size):
    import random
    return [[random.choice([0, 1]) for _ in range(size)] for _ in range(size)]

def update_grid(grid):
    size = len(grid)
    new_grid = [[0 for _ in range(size)] for _ in range(size)]
    for i in range(size):
        for j in range(size):
            neighbors = sum((grid[(i + dx) % size][(j + dy) % size] for dx in (-1, 0, 1) for dy in (-1, 0, 1) if (dx, dy) != (0, 0)))
            new_grid[i][j] = 1 if neighbors == 3 else grid[i][j] if neighbors == 2 else 0
    return new_grid

def main():
    grid = initialize_grid(10)
    while True:
        grid = update_grid(grid)
        for row in grid:
            print(''.join(('O' if cell else ' ' for cell in row)))
        print()
main()