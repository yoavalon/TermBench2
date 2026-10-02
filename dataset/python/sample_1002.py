def update_grid(grid):
    rows, cols = (len(grid), len(grid[0]))
    new_grid = [[0] * cols for _ in range(rows)]
    for i in range(rows):
        for j in range(cols):
            neighbors = sum((grid[x][y] for x in range(max(0, i - 1), min(rows, i + 2)) for y in range(max(0, j - 1), min(cols, j + 2)) if (x, y) != (i, j)))
            if grid[i][j] == 1 and (neighbors == 2 or neighbors == 3):
                new_grid[i][j] = 1
            elif grid[i][j] == 0 and neighbors == 3:
                new_grid[i][j] = 1
    return new_grid

def simulate(grid):
    import sys
    sys.setrecursionlimit(1500)
    print_grid(grid)
    simulate(update_grid(grid))

def print_grid(grid):
    for row in grid:
        print(''.join(('O' if cell else ' ' for cell in row)))
    print()

def main():
    initial_grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]
    simulate(initial_grid)
main()