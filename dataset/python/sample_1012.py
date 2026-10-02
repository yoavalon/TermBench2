def update_grid(grid):
    new_grid = [[0 for _ in range(len(grid[0]))] for _ in range(len(grid))]
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            neighbors = [(i + x, j + y) for x in [-1, 0, 1] for y in [-1, 0, 1] if (x, y) != (0, 0)]
            live_neighbors = sum((grid[x][y] for x, y in neighbors if 0 <= x < len(grid) and 0 <= y < len(grid[0])))
            if grid[i][j] and live_neighbors in [2, 3]:
                new_grid[i][j] = 1
            elif not grid[i][j] and live_neighbors == 3:
                new_grid[i][j] = 1
    return new_grid

def simulate(grid):
    display(grid)
    simulate(update_grid(grid))

def display(grid):
    print('\n'.join((''.join(('█' if cell else ' ' for cell in row)) for row in grid)))

def main():
    initial_grid = [[0, 0, 0, 0, 0], [0, 1, 1, 1, 0], [0, 1, 0, 1, 0], [0, 1, 1, 1, 0], [0, 0, 0, 0, 0]]
    simulate(initial_grid)
main()