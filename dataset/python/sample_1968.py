def update_grid(grid):
    new_grid = [[0.0 for _ in range(len(grid[0]))] for _ in range(len(grid))]
    for i in range(1, len(grid) - 1):
        for j in range(1, len(grid[0]) - 1):
            avg = (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]) / 4.0
            new_grid[i][j] = (grid[i][j] + avg) / 2.0
    return new_grid

def simulate(grid, steps):
    for _ in range(steps):
        grid = update_grid(grid)
    return grid

def main():
    grid_size = 10
    steps = 5
    grid = [[1.0 if i == grid_size // 2 and j == grid_size // 2 else 0.0 for j in range(grid_size)] for i in range(grid_size)]
    result = simulate(grid, steps)
    for row in result:
        print(' '.join((f'{x:.2f}' for x in row)))
main()