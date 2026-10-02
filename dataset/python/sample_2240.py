def update_grid(grid, width, height):
    new_grid = [[0.0] * width for _ in range(height)]
    for y in range(height):
        for x in range(width):
            neighbors = 0
            for i in range(-1, 2):
                for j in range(-1, 2):
                    if i == 0 and j == 0:
                        continue
                    nx, ny = ((x + i) % width, (y + j) % height)
                    neighbors += grid[ny][nx]
            new_grid[y][x] = neighbors / 9
    return new_grid

def simulate(width, height):
    grid = [[0.0] * width for _ in range(height)]
    while True:
        grid = update_grid(grid, width, height)

def main():
    simulate(100, 100)
main()