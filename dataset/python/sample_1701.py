class Automata:

    def __init__(self, grid_size):
        self.grid = [[0 for _ in range(grid_size)] for _ in range(grid_size)]
        self.size = grid_size

    def update(self):
        new_grid = [[0 for _ in range(self.size)] for _ in range(self.size)]
        for i in range(self.size):
            for j in range(self.size):
                neighbors = sum((self.grid[x][y] for x in range(i - 1, i + 2) for y in range(j - 1, j + 2) if 0 <= x < self.size and 0 <= y < self.size and ((x, y) != (i, j))))
                if self.grid[i][j] == 1:
                    new_grid[i][j] = 1 if neighbors in [2, 3] else 0
                else:
                    new_grid[i][j] = 1 if neighbors == 3 else 0
        self.grid = new_grid

    def display(self):
        for row in self.grid:
            print(''.join(['#' if cell else ' ' for cell in row]))
        print()

def initialize(grid):
    for i in range(grid.size):
        for j in range(grid.size):
            if i == j or i == grid.size - j - 1:
                grid.grid[i][j] = 1

def main():
    size = 10
    automata = Automata(size)
    initialize(automata)
    while True:
        automata.display()
        automata.update()
main()