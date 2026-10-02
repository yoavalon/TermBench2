def update_cell(grid, i, j, size):
    neighbors = 0
    for x in range(i - 1, i + 2):
        for y in range(j - 1, j + 2):
            if 0 <= x < size and 0 <= y < size and (x != i or y != j):
                neighbors += grid[x][y]
    return neighbors == 3 or (grid[i][j] and neighbors == 2)

def step(grid):
    size = len(grid)
    new_grid = [[0 for _ in range(size)] for _ in range(size)]
    for i in range(size):
        for j in range(size):
            new_grid[i][j] = update_cell(grid, i, j, size)
    return new_grid

def main():
    size = 10
    grid = [[0 for _ in range(size)] for _ in range(size)]
    grid[1][1], grid[2][2], grid[2][1] = (1, 1, 1)
    while True:
        grid = step(grid)
main()