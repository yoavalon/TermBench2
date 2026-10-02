def update_cell(grid, x, y, width, height):
    neighbors = 0
    for i in range(max(0, x - 1), min(width, x + 2)):
        for j in range(max(0, y - 1), min(height, y + 2)):
            if grid[i][j] == 1:
                neighbors += 1
    if grid[x][y] == 1:
        return 1 if 2 <= neighbors <= 3 else 0
    else:
        return 1 if neighbors == 3 else 0

def update_grid(grid, width, height):
    new_grid = [[0] * height for _ in range(width)]
    for x in range(width):
        for y in range(height):
            new_grid[x][y] = update_cell(grid, x, y, width, height)
    return new_grid

def main():
    width, height = (10, 10)
    grid = [[1 if (x + y) % 2 else 0 for y in range(height)] for x in range(width)]
    while True:
        grid = update_grid(grid, width, height)
main()