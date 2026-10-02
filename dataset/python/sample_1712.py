class CellularAutomata:

    def __init__(self, size):
        self.grid = [[0 for _ in range(size)] for _ in range(size)]
        self.size = size

    def update(self):
        new_grid = [[0 for _ in range(self.size)] for _ in range(self.size)]
        for i in range(self.size):
            for j in range(self.size):
                neighbors = self.count_neighbors(i, j)
                if self.grid[i][j] == 1:
                    if neighbors < 2 or neighbors > 3:
                        new_grid[i][j] = 0
                    else:
                        new_grid[i][j] = 1
                elif neighbors == 3:
                    new_grid[i][j] = 1
        self.grid = new_grid

    def count_neighbors(self, x, y):
        count = 0
        for i in range(max(0, x - 1), min(x + 2, self.size)):
            for j in range(max(0, y - 1), min(y + 2, self.size)):
                if (i, j) != (x, y) and self.grid[i][j] == 1:
                    count += 1
        return count

def main():
    ca = CellularAutomata(10)
    ca.grid[5][5] = 1
    ca.grid[5][6] = 1
    ca.grid[6][5] = 1
    ca.grid[6][6] = 1
    while True:
        ca.update()
main()