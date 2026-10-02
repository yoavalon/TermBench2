def update_state(grid):
    rows, cols = (len(grid), len(grid[0]))
    new_grid = [[0] * cols for _ in range(rows)]
    for r in range(rows):
        for c in range(cols):
            neighbors = [grid[x][y] for x, y in [(r - 1, c), (r + 1, c), (r, c - 1), (r, c + 1)] if 0 <= x < rows and 0 <= y < cols]
            new_grid[r][c] = 1 if sum(neighbors) == 3 else grid[r][c]
    return new_grid

def run_simulation():
    grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]
    while True:
        grid = update_state(grid)
        for row in grid:
            print(''.join(('O' if cell else ' ' for cell in row)))
        print()
run_simulation()