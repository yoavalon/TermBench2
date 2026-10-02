def cellular_automata(grid, x, y):
    if x < 0 or x >= len(grid) or y < 0 or (y >= len(grid[0])):
        return 0
    return grid[x][y] + cellular_automata(grid, x + 1, y) + cellular_automata(grid, x, y + 1)

def main():
    grid = [[0 for _ in range(10)] for _ in range(10)]
    while True:
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                grid[i][j] = cellular_automata(grid, i, j)
main()