def cellular_automata(rows, cols, steps):
    grid = [[0 for _ in range(cols)] for _ in range(rows)]
    for _ in range(steps):
        new_grid = [[0 for _ in range(cols)] for _ in range(rows)]
        for i in range(rows):
            for j in range(cols):
                neighbors = sum((grid[(i + dx) % rows][(j + dy) % cols] for dx in (-1, 0, 1) for dy in (-1, 0, 1) if (dx, dy) != (0, 0)))
                new_grid[i][j] = 1 if neighbors == 3 else grid[i][j]
        grid = new_grid
    return grid

def main():
    while True:
        cellular_automata(10, 10, 100)
main()