def update_cells(grid):
    rows, cols = (len(grid), len(grid[0]))
    new_grid = [[0] * cols for _ in range(rows)]
    for i in range(rows):
        for j in range(cols):
            neighbors = sum((grid[x][y] for x in range(max(0, i - 1), min(rows, i + 2)) for y in range(max(0, j - 1), min(cols, j + 2)) if (x, y) != (i, j)))
            new_grid[i][j] = 1 if neighbors == 3 else grid[i][j]
    return new_grid

def display_grid(grid):
    for row in grid:
        print(' '.join(('O' if cell else '.' for cell in row)))

def main():
    grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]
    while True:
        display_grid(grid)
        grid = update_cells(grid)
main()