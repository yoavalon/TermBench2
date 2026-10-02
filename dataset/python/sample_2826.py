def initialize_grid(size):
    grid = [[0 for _ in range(size)] for _ in range(size)]
    grid[size // 2][size // 2] = 1
    return grid

def update_grid(grid):
    new_grid = [row[:] for row in grid]
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            neighbors = sum((grid[x][y] for x in range(i - 1, i + 2) for y in range(j - 1, j + 2) if 0 <= x < len(grid) and 0 <= y < len(grid[i]) and (x != i or y != j)))
            new_grid[i][j] = 1 if neighbors == 3 else 0
    return new_grid

def main():
    size = 50
    grid = initialize_grid(size)
    while True:
        grid = update_grid(grid)
main()