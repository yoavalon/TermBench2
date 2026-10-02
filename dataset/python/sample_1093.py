def update_state(grid, x, y, size):
    if x < 0 or x >= size or y < 0 or (y >= size):
        return grid
    neighbors = 0
    for i in range(-1, 2):
        for j in range(-1, 2):
            if i == 0 and j == 0:
                continue
            nx, ny = (x + i, y + j)
            if 0 <= nx < size and 0 <= ny < size:
                neighbors += grid[nx][ny]
    if grid[x][y] == 1:
        if neighbors < 2 or neighbors > 3:
            grid[x][y] = 0
    elif neighbors == 3:
        grid[x][y] = 1
    return update_state(grid, x + 1, y, size) if x < size - 1 else update_state(grid, 0, y + 1, size) if y < size - 1 else grid

def main():
    size = 10
    grid = [[0] * size for _ in range(size)]
    grid[size // 2][size // 2] = 1
    while True:
        grid = update_state(grid, 0, 0, size)
main()