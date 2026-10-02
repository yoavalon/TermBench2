def initialize_grid(size):
    grid = [[0 for _ in range(size)] for _ in range(size)]
    grid[size // 2][size // 2] = 1
    return grid

def update_grid(grid):
    size = len(grid)
    new_grid = [[0 for _ in range(size)] for _ in range(size)]
    for i in range(size):
        for j in range(size):
            neighbors = sum((grid[x][y] for x in range(max(0, i - 1), min(size, i + 2)) for y in range(max(0, j - 1), min(size, j + 2)) if (x, y) != (i, j)))
            new_grid[i][j] = 1 if neighbors == 3 else 0
    return new_grid

def main():
    size = 10
    grid = initialize_grid(size)
    while True:
        grid = update_grid(grid)
main()