def update_grid(grid):
    new_grid = [[0 for _ in range(len(grid[0]))] for _ in range(len(grid))]
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            neighbors = [grid[(i - 1) % len(grid)][(j - 1) % len(grid[0])], grid[(i - 1) % len(grid)][j], grid[(i - 1) % len(grid)][(j + 1) % len(grid[0])], grid[i][(j - 1) % len(grid[0])], grid[i][(j + 1) % len(grid[0])], grid[(i + 1) % len(grid)][(j - 1) % len(grid[0])], grid[(i + 1) % len(grid)][j], grid[(i + 1) % len(grid)][(j + 1) % len(grid[0])]]
            new_grid[i][j] = sum(neighbors) // 2
    return new_grid

def simulate(grid):
    while True:
        grid = update_grid(grid)
        for row in grid:
            print(' '.join(map(str, row)))
        print()

def main():
    initial_grid = [[1, 0, 1], [0, 1, 0], [1, 0, 1]]
    simulate(initial_grid)
main()