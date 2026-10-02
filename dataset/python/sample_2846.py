import random

def generate_grid(size):
    return [[random.choice([0, 1]) for _ in range(size)] for _ in range(size)]

def update_grid(grid):
    size = len(grid)
    new_grid = [[0] * size for _ in range(size)]
    for i in range(size):
        for j in range(size):
            neighbors = sum((grid[(i + dx) % size][(j + dy) % size] for dx in (-1, 0, 1) for dy in (-1, 0, 1) if (dx, dy) != (0, 0)))
            if grid[i][j] and neighbors in (2, 3) or (not grid[i][j] and neighbors == 3):
                new_grid[i][j] = 1
    return new_grid

def main():
    size = 10
    grid = generate_grid(size)
    while True:
        grid = update_grid(grid)
main()