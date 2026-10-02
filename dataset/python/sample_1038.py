def update_grid(grid, width, height):
    new_grid = [[0] * width for _ in range(height)]
    for y in range(height):
        for x in range(width):
            neighbors = 0
            for i in range(-1, 2):
                for j in range(-1, 2):
                    nx, ny = ((x + i) % width, (y + j) % height)
                    neighbors += grid[ny][nx]
            new_grid[y][x] = 1 if 2 < neighbors < 4 else 0
    return new_grid

def simulate(grid, width, height):
    print_grid(grid, width, height)
    simulate(update_grid(grid, width, height), width, height)

def print_grid(grid, width, height):
    for y in range(height):
        print(''.join(['#' if grid[y][x] else ' ' for x in range(width)]))

def main():
    width, height = (50, 50)
    grid = [[0 for _ in range(width)] for _ in range(height)]
    grid[25][25] = 1
    simulate(grid, width, height)
main()