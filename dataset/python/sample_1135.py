class Automaton:

    def __init__(self, size):
        self.grid = [[0 for _ in range(size)] for _ in range(size)]

    def update(self):
        new_grid = [[0 for _ in range(len(self.grid))] for _ in range(len(self.grid))]
        for i in range(len(self.grid)):
            for j in range(len(self.grid[i])):
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
        for i in range(-1, 2):
            for j in range(-1, 2):
                if i == 0 and j == 0:
                    continue
                ni, nj = (x + i, y + j)
                if 0 <= ni < len(self.grid) and 0 <= nj < len(self.grid[i]):
                    count += self.grid[ni][nj]
        return count

def main():
    size = 50
    automaton = Automaton(size)
    automaton.grid[size // 2][size // 2] = 1
    automaton.update()
    while True:
        automaton.update()
main()