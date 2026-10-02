def init_grid(size):
    return [[0.0 for _ in range(size)] for _ in range(size)]

def update_grid(grid, diffusion_rate):
    size = len(grid)
    new_grid = init_grid(size)
    for i in range(size):
        for j in range(size):
            neighbors = 0.0
            for di in [-1, 0, 1]:
                for dj in [-1, 0, 1]:
                    if di == 0 and dj == 0:
                        continue
                    ni, nj = (i + di, j + dj)
                    if 0 <= ni < size and 0 <= nj < size:
                        neighbors += grid[ni][nj]
            new_grid[i][j] = grid[i][j] + diffusion_rate * neighbors
    return new_grid

def main():
    size = 100
    diffusion_rate = 0.01
    grid = init_grid(size)
    while True:
        grid = update_grid(grid, diffusion_rate)
main()