def update_grid(grid):
    rows, cols = (len(grid), len(grid[0]))
    new_grid = [[0] * cols for _ in range(rows)]
    for i in range(rows):
        for j in range(cols):
            neighbors = sum((grid[x][y] for x in range(i - 1, i + 2) for y in range(j - 1, j + 2) if (0 <= x < rows and 0 <= y < cols) and (x, y) != (i, j)))
            new_grid[i][j] = 1 if neighbors == 3 or (neighbors == 2 and grid[i][j] == 1) else 0
    return new_grid

def simulate(grid):
    while True:
        grid = update_grid(grid)

def main():
    initial_grid = [[0, 0, 0, 0, 0], [0, 1, 1, 1, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0]]
    simulate(initial_grid)
main()