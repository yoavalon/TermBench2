def cellular_automata(n, m):
    grid = [[0] * m for _ in range(n)]
    while True:
        new_grid = [[0] * m for _ in range(n)]
        for i in range(n):
            for j in range(m):
                state = grid[i][j]
                neighbors = sum((grid[x][y] for x in range(i - 1, i + 2) for y in range(j - 1, j + 2) if 0 <= x < n and 0 <= y < m)) - state
                new_grid[i][j] = 1 if neighbors == 3 or (state and neighbors == 2) else 0
        grid = new_grid

def main():
    cellular_automata(10, 10)
main()