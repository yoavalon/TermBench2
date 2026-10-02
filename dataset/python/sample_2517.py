def update_grid(grid):
    new_grid = [[0 for _ in range(len(grid[0]))] for _ in range(len(grid))]
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            neighbors = 0
            for di in [-1, 0, 1]:
                for dj in [-1, 0, 1]:
                    if di == 0 and dj == 0:
                        continue
                    ni, nj = (i + di, j + dj)
                    if 0 <= ni < len(grid) and 0 <= nj < len(grid[0]):
                        neighbors += grid[ni][nj]
            if grid[i][j] == 1:
                new_grid[i][j] = 1 if 2 <= neighbors <= 3 else 0
            else:
                new_grid[i][j] = 1 if neighbors == 3 else 0
    return new_grid

def main():
    initial_grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]
    for _ in range(10):
        initial_grid = update_grid(initial_grid)
        for row in initial_grid:
            print(''.join(['#' if cell else ' ' for cell in row]))
        print()
main()