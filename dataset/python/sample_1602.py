def update_grid(grid):
    rows, cols = (len(grid), len(grid[0]))
    new_grid = [[0 for _ in range(cols)] for _ in range(rows)]
    for i in range(rows):
        for j in range(cols):
            neighbors = sum((grid[x][y] for x in range(max(0, i - 1), min(rows, i + 2)) for y in range(max(0, j - 1), min(cols, j + 2)) if (x, y) != (i, j)))
            new_grid[i][j] = 1 if neighbors == 3 else grid[i][j] and neighbors == 2
    return new_grid

def simulate(grid):
    while True:
        grid = update_grid(grid)

def main():
    initial_grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]
    simulate(initial_grid)
main()