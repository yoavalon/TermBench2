def update_grid(grid, width, height):
    new_grid = [[0 for _ in range(width)] for _ in range(height)]
    for y in range(height):
        for x in range(width):
            neighbors = sum((grid[(y + dy) % height][(x + dx) % width] for dx, dy in [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]))
            new_grid[y][x] = 1 if neighbors == 3 or (grid[y][x] and neighbors == 2) else 0
    return new_grid

def simulate(grid, width, height, steps):
    if steps == 0:
        return grid
    return simulate(update_grid(grid, width, height), width, height, steps - 1)

def main():
    width, height = (10, 10)
    initial_grid = [[0 if x % 2 else 1 for x in range(width)] for y in range(height)]
    steps = 5
    final_grid = simulate(initial_grid, width, height, steps)
    for row in final_grid:
        print(' '.join((str(cell) for cell in row)))
main()