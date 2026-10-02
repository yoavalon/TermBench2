def update_grid(grid, width, height):
    new_grid = [[0.0 for _ in range(width)] for _ in range(height)]
    for y in range(height):
        for x in range(width):
            neighbors = [grid[(y + dy) % height][(x + dx) % width] for dy in [-1, 0, 1] for dx in [-1, 0, 1] if dy != 0 or dx != 0]
            new_grid[y][x] = sum(neighbors) / len(neighbors)
    return new_grid

def simulate(width, height, steps):
    grid = [[float(x + y) for x in range(width)] for y in range(height)]
    for _ in range(steps):
        grid = update_grid(grid, width, height)
    return grid

def main():
    width, height, steps = (10, 10, 5)
    final_grid = simulate(width, height, steps)
    for row in final_grid:
        print(row)
main()