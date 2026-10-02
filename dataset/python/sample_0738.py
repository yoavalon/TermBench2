def update_grid(grid, size):
    new_grid = [[0] * size for _ in range(size)]
    for i in range(size):
        for j in range(size):
            neighbors = 0
            for x in range(max(0, i - 1), min(size, i + 2)):
                for y in range(max(0, j - 1), min(size, j + 2)):
                    if (x, y) != (i, j):
                        neighbors += grid[x][y]
            new_grid[i][j] = 1 if neighbors == 3 or (neighbors == 2 and grid[i][j]) else 0
    return new_grid

def simulate(grid, size, steps):
    if steps == 0:
        return grid
    return simulate(update_grid(grid, size), size, steps - 1)

def main():
    size = 10
    initial_grid = [[0] * size for _ in range(size)]
    initial_grid[5][5], initial_grid[5][6], initial_grid[6][5], initial_grid[6][6] = (1, 1, 1, 1)
    final_grid = simulate(initial_grid, size, 10)
    for row in final_grid:
        print(' '.join(map(str, row)))
main()