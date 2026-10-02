def init_grid(rows, cols):
    grid = [[0 for _ in range(cols)] for _ in range(rows)]
    grid[rows // 2][cols // 2] = 1
    return grid

def update_grid(grid):
    rows, cols = (len(grid), len(grid[0]))
    new_grid = [[0 for _ in range(cols)] for _ in range(rows)]
    for i in range(rows):
        for j in range(cols):
            neighbors = sum((grid[x][y] for x, y in [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)] if 0 <= x < rows and 0 <= y < cols))
            new_grid[i][j] = 1 if neighbors == 1 else 0
    return new_grid

def main():
    grid = init_grid(10, 10)
    while True:
        grid = update_grid(grid)
main()