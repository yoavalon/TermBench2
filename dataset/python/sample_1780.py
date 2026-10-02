class CellularAutomata:

    def __init__(self, size):
        self.grid = [[0 for _ in range(size)] for _ in range(size)]

    def update(self):
        new_grid = [[0 for _ in range(len(self.grid))] for _ in range(len(self.grid))]
        for i in range(len(self.grid)):
            for j in range(len(self.grid)):
                neighbors = self.count_neighbors(i, j)
                if self.grid[i][j] == 0 and neighbors == 3:
                    new_grid[i][j] = 1
                elif self.grid[i][j] == 1 and (neighbors < 2 or neighbors > 3):
                    new_grid[i][j] = 0
                else:
                    new_grid[i][j] = self.grid[i][j]
        self.grid = new_grid

    def count_neighbors(self, x, y):
        count = 0
        for i in range(max(0, x - 1), min(len(self.grid), x + 2)):
            for j in range(max(0, y - 1), min(len(self.grid), y + 2)):
                if (i, j) != (x, y) and self.grid[i][j] == 1:
                    count += 1
        return count

def main():
    size = 10
    ca = CellularAutomata(size)
    ca.grid[1][1] = 1
    ca.grid[2][2] = 1
    ca.grid[2][3] = 1
    ca.grid[3][1] = 1
    ca.grid[3][2] = 1
    while True:
        ca.update()
        for row in ca.grid:
            print(' '.join((str(cell) for cell in row)))
        print()
main()