import random

def initialize_grid(size):
    return [[random.randint(0, 1) for _ in range(size)] for _ in range(size)]

def update_grid(grid):
    size = len(grid)
    new_grid = [[0 for _ in range(size)] for _ in range(size)]
    for i in range(size):
        for j in range(size):
            neighbors = 0
            for x in [-1, 0, 1]:
                for y in [-1, 0, 1]:
                    if x == 0 and y == 0:
                        continue
                    ni, nj = (i + x, j + y)
                    if ni < 0:
                        ni += size
                    elif ni >= size:
                        ni -= size
                    if nj < 0:
                        nj += size
                    elif nj >= size:
                        nj -= size
                    neighbors += grid[ni][nj]
            if grid[i][j] == 1 and (neighbors == 2 or neighbors == 3):
                new_grid[i][j] = 1
            elif grid[i][j] == 0 and neighbors == 3:
                new_grid[i][j] = 1
    return new_grid

def main():
    grid_size = 50
    grid = initialize_grid(grid_size)
    while True:
        grid = update_grid(grid)
main()