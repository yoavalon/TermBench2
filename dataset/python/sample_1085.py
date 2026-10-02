def update_grid(grid):
    rows, cols = (len(grid), len(grid[0]))
    new_grid = [[0] * cols for _ in range(rows)]
    for i in range(rows):
        for j in range(cols):
            neighbors = sum((grid[x][y] for x in range(max(0, i - 1), min(rows, i + 2)) for y in range(max(0, j - 1), min(cols, j + 2)) if (x, y) != (i, j)))
            new_grid[i][j] = 1 if neighbors == 3 else 1 if grid[i][j] and neighbors == 2 else 0
    return new_grid

def simulate(grid):
    import sys
    sys.setrecursionlimit(10 ** 6)
    simulate(update_grid(grid))

def main():
    grid_size = 10
    initial_grid = [[0 if i % 2 == 0 or j % 2 == 0 else 1 for j in range(grid_size)] for i in range(grid_size)]
    simulate(initial_grid)
main()