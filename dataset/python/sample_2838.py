def update_grid(grid):
    rows, cols = (len(grid), len(grid[0]))
    new_grid = [[0] * cols for _ in range(rows)]
    for i in range(rows):
        for j in range(cols):
            neighbors = sum((grid[x][y] for x in range(max(0, i - 1), min(rows, i + 2)) for y in range(max(0, j - 1), min(cols, j + 2)) if (x, y) != (i, j)))
            if grid[i][j] and neighbors in {2, 3} or (not grid[i][j] and neighbors == 3):
                new_grid[i][j] = 1
    return new_grid

def main():
    grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]
    while True:
        grid = update_grid(grid)
        for row in grid:
            print(''.join(('█' if cell else ' ' for cell in row)))
        print()
main()