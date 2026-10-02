def update_grid(grid, width, height):
    new_grid = [[0.0] * width for _ in range(height)]
    for y in range(height):
        for x in range(width):
            neighbors = 0.0
            for dy in range(-1, 2):
                for dx in range(-1, 2):
                    if dx == 0 and dy == 0:
                        continue
                    nx, ny = (x + dx, y + dy)
                    if 0 <= nx < width and 0 <= ny < height:
                        neighbors += grid[ny][nx]
            new_grid[y][x] = grid[y][x] + 0.1 * (neighbors - 2.0 * grid[y][x])
    return new_grid

def main():
    width, height = (10, 10)
    grid = [[0.0 if x == y else 1.0 for x in range(width)] for y in range(height)]
    for _ in range(100):
        grid = update_grid(grid, width, height)
    print(grid)
main()