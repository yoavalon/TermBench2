def initialize_grid(size):
    import random
    return [[random.choice([0, 1]) for _ in range(size)] for _ in range(size)]

def update_grid(grid):
    size = len(grid)
    new_grid = [[0 for _ in range(size)] for _ in range(size)]
    for i in range(size):
        for j in range(size):
            neighbors = sum((grid[(i + di) % size][(j + dj) % size] for di in [-1, 0, 1] for dj in [-1, 0, 1] if (di, dj) != (0, 0)))
            new_grid[i][j] = 1 if neighbors == 3 or (grid[i][j] and neighbors == 2) else 0
    return new_grid

def simulate(steps, size):
    grid = initialize_grid(size)
    for _ in range(steps):
        grid = update_grid(grid)
    return grid

def main():
    steps, size = (10, 5)
    result = simulate(steps, size)
    for row in result:
        print(' '.join(map(str, row)))
main()