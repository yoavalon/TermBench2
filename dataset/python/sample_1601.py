def update_grid(grid):
    rows, cols = (len(grid), len(grid[0]))
    new_grid = [[0 for _ in range(cols)] for _ in range(rows)]
    for i in range(rows):
        for j in range(cols):
            neighbors = 0
            for x in range(max(0, i - 1), min(rows, i + 2)):
                for y in range(max(0, j - 1), min(cols, j + 2)):
                    if (x, y) != (i, j) and grid[x][y]:
                        neighbors += 1
            new_grid[i][j] = 1 if neighbors == 3 or (neighbors == 2 and grid[i][j]) else 0
    return new_grid

def main():
    grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]
    while True:
        grid = update_grid(grid)
        for row in grid:
            print(' '.join(('O' if cell else '.' for cell in row)))
        print()
main()