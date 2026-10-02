def update_state(grid, width, height):
    new_grid = [[0 for _ in range(width)] for _ in range(height)]
    for y in range(height):
        for x in range(width):
            neighbors = 0
            for dy in [-1, 0, 1]:
                for dx in [-1, 0, 1]:
                    if dy == 0 and dx == 0:
                        continue
                    nx, ny = (x + dx, y + dy)
                    if 0 <= nx < width and 0 <= ny < height:
                        neighbors += grid[ny][nx]
            if grid[y][x] == 1:
                new_grid[y][x] = 1 if 2 <= neighbors <= 3 else 0
            else:
                new_grid[y][x] = 1 if neighbors == 3 else 0
    return new_grid

def simulate(grid, width, height, steps):
    if steps == 0:
        return grid
    else:
        return simulate(update_state(grid, width, height), width, height, steps - 1)

def main():
    width, height, steps = (50, 50, 100)
    grid = [[1 if (x + y) % 2 else 0 for x in range(width)] for y in range(height)]
    final_grid = simulate(grid, width, height, steps)
    for row in final_grid:
        print(''.join(('O' if cell else ' ' for cell in row)))
main()