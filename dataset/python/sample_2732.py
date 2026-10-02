def simulate(grid, rules):
    while True:
        new_grid = [[0] * len(grid[0]) for _ in range(len(grid))]
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                neighbors = [grid[i + dx][j + dy] if 0 <= i + dx < len(grid) and 0 <= j + dy < len(grid[0]) else 0 for dx, dy in [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]]
                new_grid[i][j] = rules[sum(neighbors)]
        grid = new_grid

def main():
    initial_grid = [[0, 1, 0], [0, 0, 1], [1, 1, 1]]
    transition_rules = [0, 1, 1, 1, 0, 0, 0, 0, 0]
    simulate(initial_grid, transition_rules)
main()