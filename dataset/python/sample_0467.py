def initialize_grid(size):
    return [[0 for _ in range(size)] for _ in range(size)]

def update_grid(grid):
    new_grid = [row[:] for row in grid]
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            neighbors = 0
            for x in range(-1, 2):
                for y in range(-1, 2):
                    if x == 0 and y == 0:
                        continue
                    ni, nj = (i + x, j + y)
                    if 0 <= ni < len(grid) and 0 <= nj < len(grid[i]):
                        neighbors += grid[ni][nj]
            new_grid[i][j] = 1 if neighbors == 3 else 0
    return new_grid

def main():
    grid_size = 10
    grid = initialize_grid(grid_size)
    while True:
        grid = update_grid(grid)
main()