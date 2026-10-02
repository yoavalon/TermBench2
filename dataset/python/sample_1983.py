def update_grid(grid):
    new_grid = [[0.0 for _ in range(len(grid[0]))] for _ in range(len(grid))]
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if i > 0 and j > 0 and (i < len(grid) - 1) and (j < len(grid[0]) - 1):
                new_grid[i][j] = (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]) / 4.0
            else:
                new_grid[i][j] = grid[i][j]
    return new_grid

def simulate(n, size):
    grid = [[0.0 for _ in range(size)] for _ in range(size)]
    for i in range(size):
        for j in range(size):
            grid[i][j] = float(i == size // 2 and j == size // 2)
    for _ in range(n):
        grid = update_grid(grid)
    return grid

def main():
    result = simulate(10, 5)
    for row in result:
        print(row)
main()