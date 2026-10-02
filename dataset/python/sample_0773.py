def update_grid(grid, width, height):
    new_grid = [[0] * width for _ in range(height)]
    for y in range(height):
        for x in range(width):
            neighbors = sum((grid[ny][nx] for ny in range(max(0, y - 1), min(height, y + 2)) for nx in range(max(0, x - 1), min(width, x + 2)))) - grid[y][x]
            new_grid[y][x] = 1 if neighbors == 3 or (neighbors == 2 and grid[y][x] == 1) else 0
    return new_grid

def simulate(grid, width, height, steps):
    for _ in range(steps):
        grid = update_grid(grid, width, height)
    return grid

def main():
    width, height = (10, 10)
    steps = 5
    initial_grid = [[0] * width for _ in range(height)]
    initial_grid[5][5] = 1
    result = simulate(initial_grid, width, height, steps)
    for row in result:
        print(''.join(('O' if cell else ' ' for cell in row)))
main()