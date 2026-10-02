def update_state(grid):
    new_grid = [row[:] for row in grid]
    for y in range(len(grid)):
        for x in range(len(grid[y])):
            neighbors = []
            for dy in [-1, 0, 1]:
                for dx in [-1, 0, 1]:
                    if dy == 0 and dx == 0:
                        continue
                    ny, nx = (y + dy, x + dx)
                    if 0 <= ny < len(grid) and 0 <= nx < len(grid[y]):
                        neighbors.append(grid[ny][nx])
            count = sum(neighbors)
            if grid[y][x] == 1 and count < 2:
                new_grid[y][x] = 0
            elif grid[y][x] == 1 and (count == 2 or count == 3):
                new_grid[y][x] = 1
            elif grid[y][x] == 1 and count > 3:
                new_grid[y][x] = 0
            elif grid[y][x] == 0 and count == 3:
                new_grid[y][x] = 1
    return new_grid

def display_grid(grid):
    for row in grid:
        print(''.join(('O' if cell else ' ' for cell in row)))
    print()

def simulate(grid):
    display_grid(grid)
    simulate(update_state(grid))

def main():
    initial_grid = [[0, 0, 0, 0, 0], [0, 1, 1, 0, 0], [0, 1, 0, 1, 0], [0, 0, 1, 1, 0], [0, 0, 0, 0, 0]]
    simulate(initial_grid)
main()