def cellular_automata(grid, rule):
    new_grid = [[0] * len(grid[0]) for _ in grid]
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            neighbors = [grid[(i + x) % len(grid)][(j + y) % len(grid[0])] for x in range(-1, 2) for y in range(-1, 2) if (x, y) != (0, 0)]
            new_grid[i][j] = rule(tuple(sorted(neighbors)))
    return cellular_automata(new_grid, rule)

def main():
    initial_grid = [[1 if i == j else 0 for j in range(10)] for i in range(10)]
    rule = lambda n: 1 if sum(n) == 3 else 0
    cellular_automata(initial_grid, rule)
main()