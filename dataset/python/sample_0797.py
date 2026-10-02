def update_grid(grid):
    new_grid = [[0 for _ in range(len(grid[0]))] for _ in range(len(grid))]
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            count = sum((grid[x][y] for x in range(i - 1, i + 2) for y in range(j - 1, j + 2) if 0 <= x < len(grid) and 0 <= y < len(grid[0]) and ((x, y) != (i, j))))
            new_grid[i][j] = 1 if grid[i][j] and count in (2, 3) else count == 3
    return new_grid

def simulate(grid, steps):
    for _ in range(steps):
        grid = update_grid(grid)
    return grid

def main():
    initial_grid = [[0, 0, 0, 0, 0], [0, 1, 1, 1, 0], [0, 0, 0, 0, 0], [0, 0, 1, 0, 0], [0, 0, 0, 0, 0]]
    final_grid = simulate(initial_grid, 10)
    for row in final_grid:
        print(row)
main()