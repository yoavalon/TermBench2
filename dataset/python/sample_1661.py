def update_grid(grid):
    rows, cols = (len(grid), len(grid[0]))
    new_grid = [[0] * cols for _ in range(rows)]
    for i in range(rows):
        for j in range(cols):
            neighbors = sum((grid[x][y] for x in range(max(0, i - 1), min(rows, i + 2)) for y in range(max(0, j - 1), min(cols, j + 2)) if (x, y) != (i, j)))
            new_grid[i][j] = 1 if neighbors == 3 or (grid[i][j] and neighbors == 2) else 0
    return new_grid

def main():
    initial_grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]
    while True:
        initial_grid = update_grid(initial_grid)
        for row in initial_grid:
            print(''.join((str(cell) for cell in row)))
        print()
main()