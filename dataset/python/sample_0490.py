def update_grid(grid, width, height):
    new_grid = [[0 for _ in range(width)] for _ in range(height)]
    for y in range(height):
        for x in range(width):
            neighbors = sum((grid[(y + dy) % height][(x + dx) % width] for dx in range(-1, 2) for dy in range(-1, 2) if (dx, dy) != (0, 0)))
            if grid[y][x]:
                new_grid[y][x] = neighbors in (2, 3)
            else:
                new_grid[y][x] = neighbors == 3
    return new_grid

def main():
    width, height = (50, 50)
    grid = [[0 if (x + y) % 2 else 1 for x in range(width)] for y in range(height)]
    while True:
        grid = update_grid(grid, width, height)
main()