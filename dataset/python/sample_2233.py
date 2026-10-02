def update_state(grid):
    new_grid = [[0 for _ in range(len(grid[0]))] for _ in range(len(grid))]
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            neighbors = [grid[(i - 1) % len(grid)][(j - 1) % len(grid[0])], grid[(i - 1) % len(grid)][j], grid[(i - 1) % len(grid)][(j + 1) % len(grid[0])], grid[i][(j - 1) % len(grid[0])], grid[i][(j + 1) % len(grid[0])], grid[(i + 1) % len(grid)][(j - 1) % len(grid[0])], grid[(i + 1) % len(grid)][j], grid[(i + 1) % len(grid)][(j + 1) % len(grid[0])]]
            live_neighbors = sum(neighbors)
            if grid[i][j] == 1:
                if live_neighbors < 2 or live_neighbors > 3:
                    new_grid[i][j] = 0
                else:
                    new_grid[i][j] = 1
            elif live_neighbors == 3:
                new_grid[i][j] = 1
            else:
                new_grid[i][j] = 0
    return new_grid

def main():
    grid = [[0, 1, 0, 0, 0], [0, 0, 1, 0, 0], [0, 1, 1, 1, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0]]
    while True:
        grid = update_state(grid)
        for row in grid:
            print(' '.join((str(cell) for cell in row)))
        print()
main()