def update_state(grid):
    new_grid = [[0] * len(grid[0]) for _ in range(len(grid))]
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            neighbors = sum((grid[x][y] for x in range(max(0, i - 1), min(i + 2, len(grid))) for y in range(max(0, j - 1), min(j + 2, len(grid[0]))) if (x, y) != (i, j)))
            new_grid[i][j] = 1 if neighbors == 3 else 0 if neighbors < 2 or neighbors > 3 else grid[i][j]
    return new_grid

def main():
    grid = [[0, 1, 0], [1, 1, 1], [0, 1, 0]]
    while True:
        grid = update_state(grid)
        for row in grid:
            print(' '.join(map(str, row)))
        print('-' * len(grid[0]) * 2)
main()