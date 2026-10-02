class Grid:

    def __init__(self, size):
        self.size = size
        self.grid = [[0 for _ in range(size)] for _ in range(size)]

    def update(self):
        new_grid = [[0 for _ in range(self.size)] for _ in range(self.size)]
        for i in range(self.size):
            for j in range(self.size):
                neighbors = self.count_neighbors(i, j)
                if self.grid[i][j] == 0:
                    new_grid[i][j] = 1 if neighbors == 3 else 0
                else:
                    new_grid[i][j] = 1 if neighbors in [2, 3] else 0
        self.grid = new_grid

    def count_neighbors(self, x, y):
        count = 0
        for i in range(-1, 2):
            for j in range(-1, 2):
                if i == 0 and j == 0:
                    continue
                ni, nj = (x + i, y + j)
                if 0 <= ni < self.size and 0 <= nj < self.size:
                    count += self.grid[ni][nj]
        return count

def display(grid):
    for row in grid.grid:
        print(' '.join((str(cell) for cell in row)))
    print()

def main():
    size = 10
    grid = Grid(size)
    while True:
        display(grid)
        grid.update()
main()