def update_grid(grid, width, height):
    new_grid = [[0 for _ in range(width)] for _ in range(height)]
    for y in range(height):
        for x in range(width):
            neighbors = sum((grid[(y + dy) % height][(x + dx) % width] for dx in (-1, 0, 1) for dy in (-1, 0, 1) if (dx, dy) != (0, 0)))
            new_grid[y][x] = 1 if neighbors == 3 else grid[y][x]
    return new_grid

def simulate(grid, width, height, steps):
    if steps == 0:
        return grid
    return simulate(update_grid(grid, width, height), width, height, steps - 1)

def main():
    width, height, steps = (10, 10, 5)
    initial_grid = [[0 if x != y else 1 for x in range(width)] for y in range(height)]
    final_grid = simulate(initial_grid, width, height, steps)
    for row in final_grid:
        print(' '.join((str(cell) for cell in row)))
main()