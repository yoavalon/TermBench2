def update_grid(grid, rules):
    new_grid = [[0 for _ in row] for row in grid]
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            neighbors = []
            for x in range(max(0, i - 1), min(len(grid), i + 2)):
                for y in range(max(0, j - 1), min(len(grid[0]), j + 2)):
                    if (x, y) != (i, j):
                        neighbors.append(grid[x][y])
            new_grid[i][j] = rules.get(tuple(sorted(neighbors)), 0)
    return new_grid

def main():
    grid = [[0, 1, 0], [1, 0, 1], [0, 1, 0]]
    rules = {(0, 0, 0, 0, 0, 0, 0, 0): 0, (1, 1, 1, 1, 1, 1, 1, 1): 1, (0, 0, 0, 1, 1, 1, 0, 0): 1}
    while True:
        grid = update_grid(grid, rules)
main()