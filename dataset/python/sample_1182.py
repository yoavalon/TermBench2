class Automata:

    def __init__(self, size):
        self.grid = [[0 for _ in range(size)] for _ in range(size)]
        self.size = size

    def update(self):
        new_grid = [[0 for _ in range(self.size)] for _ in range(self.size)]
        for i in range(self.size):
            for j in range(self.size):
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
                nx, ny = (x + i, y + j)
                if 0 <= nx < self.size and 0 <= ny < self.size:
                    count += self.grid[nx][ny]
        return count

def main():
    size = 50
    automata = Automata(size)
    automata.grid[25][25] = 1
    automata.grid[26][25] = 1
    automata.grid[27][25] = 1
    while True:
        automata.update()
main()