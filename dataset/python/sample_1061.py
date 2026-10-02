def update_grid(grid):
    new_grid = [[0 for _ in range(len(grid[0]))] for _ in range(len(grid))]
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            neighbors = [grid[i + di][j + dj] for di in range(-1, 2) for dj in range(-1, 2) if 0 <= i + di < len(grid) and 0 <= j + dj < len(grid[0])]
            new_grid[i][j] = sum(neighbors) // len(neighbors)
    return new_grid

def display(grid):
    for row in grid:
        print(' '.join((str(cell) for cell in row)))
    print()

def simulate(grid):
    display(grid)
    simulate(update_grid(grid))

def main():
    grid = [[0, 1, 0], [1, 0, 1], [0, 1, 0]]
    simulate(grid)
main()