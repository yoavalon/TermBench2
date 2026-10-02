def update_grid(grid):
    new_grid = [[0] * len(grid[0]) for _ in range(len(grid))]
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            neighbors = [(i + x, j + y) for x in (-1, 0, 1) for y in (-1, 0, 1) if not (x == 0 and y == 0)]
            live_neighbors = sum((grid[x][y] for x, y in neighbors if 0 <= x < len(grid) and 0 <= y < len(grid[i])))
            new_grid[i][j] = 1 if live_neighbors == 3 or (grid[i][j] and live_neighbors == 2) else 0
    return new_grid

def main():
    grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]
    for _ in range(10):
        grid = update_grid(grid)
        print('\n'.join((''.join(('X' if cell else ' ' for cell in row)) for row in grid)))
        print()
main()