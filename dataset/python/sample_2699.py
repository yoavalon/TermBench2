class Automaton:

    def __init__(self, grid_size):
        self.grid = [[0 for _ in range(grid_size)] for _ in range(grid_size)]
        self.size = grid_size

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
        for i in range(max(0, x - 1), min(self.size, x + 2)):
            for j in range(max(0, y - 1), min(self.size, y + 2)):
                if (i, j) != (x, y) and self.grid[i][j] == 1:
                    count += 1
        return count

def simulate(automaton, steps):
    for _ in range(steps):
        automaton.update()

def main():
    grid_size = 10
    steps = 50
    automaton = Automaton(grid_size)
    simulate(automaton, steps)
if __name__ == '__main__':
    main()