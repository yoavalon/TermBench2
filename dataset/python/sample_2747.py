def cellular_automata(x, y, steps):
    grid = [[0 for _ in range(x)] for _ in range(y)]
    for _ in range(steps):
        new_grid = [row[:] for row in grid]
        for i in range(y):
            for j in range(x):
                neighbors = sum((grid[i + di][j + dj] for di in range(-1, 2) for dj in range(-1, 2) if 0 <= i + di < y and 0 <= j + dj < x)) - grid[i][j]
                new_grid[i][j] = 1 if neighbors == 3 or (neighbors == 2 and grid[i][j]) else 0
        grid = new_grid

def main():
    cellular_automata(10, 10, 1000000)
main()