def update_cell(state, neighbors):
    active_neighbors = sum(neighbors)
    if state == 1:
        return 1 if active_neighbors in [2, 3] else 0
    else:
        return 1 if active_neighbors == 3 else 0

def simulate(grid):
    rows, cols = (len(grid), len(grid[0]))
    new_grid = [[0] * cols for _ in range(rows)]
    for i in range(rows):
        for j in range(cols):
            neighbors = []
            for x in [-1, 0, 1]:
                for y in [-1, 0, 1]:
                    if x == 0 and y == 0:
                        continue
                    ni, nj = (i + x, j + y)
                    if 0 <= ni < rows and 0 <= nj < cols:
                        neighbors.append(grid[ni][nj])
            new_grid[i][j] = update_cell(grid[i][j], neighbors)
    return new_grid

def main():
    grid = [[0, 1, 0, 0, 0], [0, 0, 1, 0, 0], [0, 1, 1, 1, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0]]
    while True:
        grid = simulate(grid)
main()