def update_state(grid):
    new_grid = [[0.0 for _ in range(len(grid[0]))] for _ in range(len(grid))]
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            neighbors = 0
            for x in [-1, 0, 1]:
                for y in [-1, 0, 1]:
                    if x == 0 and y == 0:
                        continue
                    ni, nj = (i + x, j + y)
                    if 0 <= ni < len(grid) and 0 <= nj < len(grid[0]):
                        neighbors += grid[ni][nj]
            new_grid[i][j] = neighbors / 9.0
    return new_grid

def run_simulation(steps, size):
    grid = [[float(i == j) for j in range(size)] for i in range(size)]
    for _ in range(steps):
        grid = update_state(grid)
    return grid
if __name__ == '__main__':
    result = run_simulation(10, 5)
    for row in result:
        print(row)