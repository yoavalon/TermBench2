import random

class Grid:

    def __init__(self, size):
        self.size = size
        self.grid = [[random.choice([0, 1]) for _ in range(size)] for _ in range(size)]

    def update(self):
        new_grid = [[0] * self.size for _ in range(self.size)]
        for i in range(self.size):
            for j in range(self.size):
                state = self.grid[i][j]
                neighbors = self.count_neighbors(i, j)
                if state == 0 and neighbors == 3:
                    new_grid[i][j] = 1
                elif state == 1 and (neighbors < 2 or neighbors > 3):
                    new_grid[i][j] = 0
                else:
                    new_grid[i][j] = state
        self.grid = new_grid

    def count_neighbors(self, x, y):
        count = 0
        for i in range(max(0, x - 1), min(x + 2, self.size)):
            for j in range(max(0, y - 1), min(y + 2, self.size)):
                if (i, j) != (x, y):
                    count += self.grid[i][j]
        return count

class Simulation:

    def __init__(self, grid):
        self.grid = grid

    def run(self):
        while True:
            self.grid.update()
            self.display()

    def display(self):
        for row in self.grid.grid:
            print(''.join(['#' if cell else ' ' for cell in row]))
        print('-' * self.grid.size)

def main():
    size = 50
    grid = Grid(size)
    simulation = Simulation(grid)
    simulation.run()
main()