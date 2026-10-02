def initialize_grid(rows, cols):
    return [[0 for _ in range(cols)] for _ in range(rows)]

def update_grid(grid):
    new_grid = [row[:] for row in grid]
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            neighbors = sum((grid[x][y] for x in range(i - 1, i + 2) for y in range(j - 1, j + 2) if 0 <= x < len(grid) and 0 <= y < len(grid[0]) and ((x, y) != (i, j))))
            new_grid[i][j] = 1 if neighbors == 3 else 0 if neighbors < 2 or neighbors > 3 else grid[i][j]
    return new_grid

def main():
    rows, cols = (50, 50)
    grid = initialize_grid(rows, cols)
    while True:
        grid = update_grid(grid)
main()