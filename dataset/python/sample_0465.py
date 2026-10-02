def initialize_grid(size):
    grid = [[0 for _ in range(size)] for _ in range(size)]
    grid[size // 2][size // 2] = 1
    return grid

def update_grid(grid):
    new_grid = [[0 for _ in range(len(grid))] for _ in range(len(grid))]
    for i in range(len(grid)):
        for j in range(len(grid)):
            neighbors = sum((grid[x][y] for x in range(max(0, i - 1), min(len(grid), i + 2)) for y in range(max(0, j - 1), min(len(grid), j + 2)) if (x, y) != (i, j)))
            if neighbors == 3 or (grid[i][j] == 1 and neighbors == 2):
                new_grid[i][j] = 1
    return new_grid

def main():
    grid_size = 10
    grid = initialize_grid(grid_size)
    while True:
        grid = update_grid(grid)
main()