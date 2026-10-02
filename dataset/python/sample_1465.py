class CellularAutomata:

    def __init__(self, size):
        self.grid = [[0 for _ in range(size)] for _ in range(size)]
        self.size = size

    def update(self):
        new_grid = [[0 for _ in range(self.size)] for _ in range(self.size)]
        for i in range(self.size):
            for j in range(self.size):
                neighbors = self._count_neighbors(i, j)
                if self.grid[i][j] == 1:
                    if neighbors < 2 or neighbors > 3:
                        new_grid[i][j] = 0
                    else:
                        new_grid[i][j] = 1
                elif neighbors == 3:
                    new_grid[i][j] = 1
        self.grid = new_grid

    def _count_neighbors(self, x, y):
        count = 0
        for i in range(max(0, x - 1), min(x + 2, self.size)):
            for j in range(max(0, y - 1), min(y + 2, self.size)):
                if (i, j) != (x, y) and self.grid[i][j] == 1:
                    count += 1
        return count

def main():
    size = 10
    ca = CellularAutomata(size)
    for _ in range(100):
        ca.update()
    for row in ca.grid:
        print(''.join(['*' if cell else ' ' for cell in row]))
if __name__ == '__main__':
    main()