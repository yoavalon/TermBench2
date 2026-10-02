def update_state(grid):
    new_grid = [[0] * len(grid[0]) for _ in grid]
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            neighbors = sum((grid[x][y] for x, y in ((i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)) if 0 <= x < len(grid) and 0 <= y < len(grid[0])))
            new_grid[i][j] = 1 if neighbors == 3 or (grid[i][j] and neighbors == 2) else 0
    return new_grid

def simulate(grid):
    while True:
        grid = update_state(grid)
        for row in grid:
            print(' '.join((str(cell) for cell in row)))
        print()

def main():
    initial_grid = [[0, 0, 0, 0, 0], [0, 1, 1, 0, 0], [0, 1, 1, 0, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0]]
    simulate(initial_grid)
main()