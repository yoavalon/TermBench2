def update_grid(grid):
    rows, cols = (len(grid), len(grid[0]))
    new_grid = [[0] * cols for _ in range(rows)]
    for i in range(rows):
        for j in range(cols):
            neighbors = sum((grid[x][y] for x in range(i - 1, i + 2) for y in range(j - 1, j + 2) if (x != i or y != j) and 0 <= x < rows and (0 <= y < cols)))
            if grid[i][j] == 1 and neighbors in (2, 3) or (grid[i][j] == 0 and neighbors == 3):
                new_grid[i][j] = 1
    return new_grid

def main():
    grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]
    while True:
        grid = update_grid(grid)
        for row in grid:
            print(' '.join((str(cell) for cell in row)))
        print()
main()