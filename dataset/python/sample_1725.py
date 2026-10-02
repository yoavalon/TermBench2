class Automaton:

    def __init__(self, size):
        self.grid = [[0 for _ in range(size)] for _ in range(size)]
        self.size = size

    def update(self):
        new_grid = [[0 for _ in range(self.size)] for _ in range(self.size)]
        for i in range(self.size):
            for j in range(self.size):
                neighbors = self.count_neighbors(i, j)
                if self.grid[i][j] == 0:
                    if neighbors == 3:
                        new_grid[i][j] = 1
                elif neighbors < 2 or neighbors > 3:
                    new_grid[i][j] = 0
                else:
                    new_grid[i][j] = 1
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
    for row in grid:
        print(''.join(['#' if cell else ' ' for cell in row]))

def main():
    size = 10
    automaton = Automaton(size)
    automaton.grid[5][5] = 1
    automaton.grid[5][6] = 1
    automaton.grid[6][5] = 1
    automaton.grid[6][6] = 1
    while True:
        display(automaton.grid)
        automaton.update()
main()