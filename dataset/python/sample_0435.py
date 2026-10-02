def update_grid(grid, rule):
    new_grid = [[0] * len(grid[0]) for _ in grid]
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            neighbors = [grid[(i + di) % len(grid)][(j + dj) % len(grid[0])] for di in [-1, 0, 1] for dj in [-1, 0, 1] if not (di == 0 and dj == 0)]
            new_grid[i][j] = rule(neighbors, grid[i][j])
    return new_grid

def evolve(grid, rule, steps):
    for _ in range(steps):
        grid = update_grid(grid, rule)
    return grid

def main():
    grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]

    def rule(neighbors, cell):
        return 1 if sum(neighbors) == 3 else 0
    while True:
        grid = evolve(grid, rule, 1)
main()