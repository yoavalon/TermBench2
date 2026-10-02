def simulate_flow(width, height):
    grid = [[0] * width for _ in range(height)]
    while True:
        new_grid = [row[:] for row in grid]
        for y in range(height):
            for x in range(width):
                neighbors = [grid[(y + dy) % height][(x + dx) % width] for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]]
                new_grid[y][x] = sum(neighbors) // 4
        grid = new_grid
simulate_flow(10, 10)