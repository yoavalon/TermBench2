def initialize_grid(size):
    import random
    return [[random.choice([0, 1]) for _ in range(size)] for _ in range(size)]

def update_grid(grid):
    size = len(grid)
    new_grid = [[0] * size for _ in range(size)]
    for i in range(size):
        for j in range(size):
            neighbors = sum((grid[x][y] for x in range(i - 1, i + 2) for y in range(j - 1, j + 2) if 0 <= x < size and 0 <= y < size and ((x, y) != (i, j))))
            if grid[i][j] == 1 and (neighbors < 2 or neighbors > 3):
                new_grid[i][j] = 0
            elif grid[i][j] == 0 and neighbors == 3:
                new_grid[i][j] = 1
            else:
                new_grid[i][j] = grid[i][j]
    return new_grid

def main():
    size = 5
    grid = initialize_grid(size)
    for _ in range(10):
        grid = update_grid(grid)
    for row in grid:
        print(' '.join((str(cell) for cell in row)))
main()