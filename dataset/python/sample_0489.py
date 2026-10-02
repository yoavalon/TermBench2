def update_grid(grid, width, height):
    new_grid = [[0] * width for _ in range(height)]
    for y in range(height):
        for x in range(width):
            neighbors = sum((grid[(y + dy) % height][(x + dx) % width] for dx, dy in [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]))
            if grid[y][x] == 1 and (neighbors < 2 or neighbors > 3):
                new_grid[y][x] = 0
            elif grid[y][x] == 0 and neighbors == 3:
                new_grid[y][x] = 1
            else:
                new_grid[y][x] = grid[y][x]
    return new_grid

def main():
    width, height = (10, 10)
    grid = [[int((x + y) % 2) for x in range(width)] for y in range(height)]
    while True:
        grid = update_grid(grid, width, height)
main()