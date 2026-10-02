def update_state(grid, width, height):
    new_grid = [[0 for _ in range(width)] for _ in range(height)]
    for y in range(height):
        for x in range(width):
            neighbors = 0
            for dy in range(-1, 2):
                for dx in range(-1, 2):
                    if dy == 0 and dx == 0:
                        continue
                    nx, ny = (x + dx, y + dy)
                    if 0 <= nx < width and 0 <= ny < height:
                        neighbors += grid[ny][nx]
            if grid[y][x] == 1:
                if neighbors < 2 or neighbors > 3:
                    new_grid[y][x] = 0
                else:
                    new_grid[y][x] = 1
            elif neighbors == 3:
                new_grid[y][x] = 1
    return new_grid

def run_simulation(grid, width, height, steps):
    if steps == 0:
        return grid
    else:
        grid = update_state(grid, width, height)
        return run_simulation(grid, width, height, steps - 1)

def main():
    width, height = (10, 10)
    initial_grid = [[0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 1, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 1, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 1, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]
    steps = 10
    final_grid = run_simulation(initial_grid, width, height, steps)
    for row in final_grid:
        print(row)
main()