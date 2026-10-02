class CellAutomata:

    def __init__(self, grid_size):
        self.grid_size = grid_size
        self.grid = self.initialize_grid()

    def initialize_grid(self):
        import random
        return [[random.randint(0, 1) for _ in range(self.grid_size)] for _ in range(self.grid_size)]

    def update_grid(self):
        new_grid = [[0 for _ in range(self.grid_size)] for _ in range(self.grid_size)]
        for i in range(self.grid_size):
            for j in range(self.grid_size):
                neighbors = self.count_neighbors(i, j)
                if self.grid[i][j] == 1:
                    if neighbors in (2, 3):
                        new_grid[i][j] = 1
                elif neighbors == 3:
                    new_grid[i][j] = 1
        self.grid = new_grid

    def count_neighbors(self, x, y):
        count = 0
        for i in range(-1, 2):
            for j in range(-1, 2):
                if i == 0 and j == 0:
                    continue
                ni, nj = ((x + i) % self.grid_size, (y + j) % self.grid_size)
                count += self.grid[ni][nj]
        return count

def main():
    size = 50
    automata = CellAutomata(size)
    while True:
        automata.update_grid()
main()