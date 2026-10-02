def update_grid(grid, rules):
    new_grid = [row[:] for row in grid]
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            neighbors = sum((grid[x][y] for x in range(max(0, i - 1), min(len(grid), i + 2)) for y in range(max(0, j - 1), min(len(grid[0]), j + 2)))) - grid[i][j]
            new_grid[i][j] = rules[neighbors]
    return new_grid

def simulate(grid, rules):
    import os
    os.system('cls' if os.name == 'nt' else 'clear')
    for row in grid:
        print(''.join(['#' if cell else '.' for cell in row]))
    simulate(update_grid(grid, rules), rules)

def main():
    width, height = (20, 20)
    initial_grid = [[int((i + j) % 2 == 0) for j in range(width)] for i in range(height)]
    rules = [0, 0, 1, 1, 0, 0, 0, 0, 0]
    simulate(initial_grid, rules)
main()