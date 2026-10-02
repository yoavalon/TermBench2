def update_grid(grid, width, height):
    new_grid = [[0 for _ in range(width)] for _ in range(height)]
    for y in range(height):
        for x in range(width):
            neighbors = sum((grid[(y + dy) % height][(x + dx) % width] for dx in range(-1, 2) for dy in range(-1, 2) if (dx, dy) != (0, 0)))
            new_grid[y][x] = 1 if neighbors == 3 or (grid[y][x] and neighbors == 2) else 0
    return new_grid

def simulate(grid, width, height, steps):
    if steps == 0:
        return grid
    return simulate(update_grid(grid, width, height), width, height, steps - 1)

def main():
    width, height, steps = (5, 5, 5)
    grid = [[1 if (x + y) % 2 else 0 for x in range(width)] for y in range(height)]
    final_grid = simulate(grid, width, height, steps)
    for row in final_grid:
        print(''.join(('O' if cell else ' ' for cell in row)))
main()