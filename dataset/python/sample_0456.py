def init_grid(size):
    return [[0 if x != 0 and x != size - 1 and (y != 0) and (y != size - 1) else 1 for x in range(size)] for y in range(size)]

def update_grid(grid):
    new_grid = [row[:] for row in grid]
    for y in range(1, len(grid) - 1):
        for x in range(1, len(grid[0]) - 1):
            neighbors = [grid[y + dy][x + dx] for dy, dx in [(-1, 0), (1, 0), (0, -1), (0, 1)]]
            new_grid[y][x] = 1 if sum(neighbors) >= 2 else 0
    return new_grid

def simulate(grid):
    while True:
        grid = update_grid(grid)

def main():
    size = 10
    grid = init_grid(size)
    simulate(grid)
main()