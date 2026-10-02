def update_state(grid):
    rows, cols = (len(grid), len(grid[0]))
    new_grid = [[0.0 for _ in range(cols)] for _ in range(rows)]
    for i in range(rows):
        for j in range(cols):
            neighbors = [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)]
            value = sum((grid[x][y] for x, y in neighbors if 0 <= x < rows and 0 <= y < cols))
            new_grid[i][j] = value / 4.0
    return new_grid

def simulate(grid):
    while True:
        grid = update_state(grid)

def main():
    grid_size = 10
    initial_grid = [[float(i * j) for j in range(grid_size)] for i in range(grid_size)]
    simulate(initial_grid)
main()