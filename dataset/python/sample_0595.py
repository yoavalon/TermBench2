import random

class Grid:

    def __init__(self, size):
        self.size = size
        self.grid = [[0 for _ in range(size)] for _ in range(size)]

    def update(self):
        new_grid = [[0 for _ in range(self.size)] for _ in range(self.size)]
        for i in range(self.size):
            for j in range(self.size):
                neighbors = self.count_neighbors(i, j)
                if self.grid[i][j] == 1:
                    new_grid[i][j] = 1 if neighbors in [2, 3] else 0
                else:
                    new_grid[i][j] = 1 if neighbors == 3 else 0
        self.grid = new_grid

    def count_neighbors(self, x, y):
        count = 0
        for i in range(max(0, x - 1), min(self.size, x + 2)):
            for j in range(max(0, y - 1), min(self.size, y + 2)):
                if (i, j) != (x, y):
                    count += self.grid[i][j]
        return count

class Simulation:

    def __init__(self, grid_size):
        self.grid = Grid(grid_size)
        self.populate_grid()

    def populate_grid(self):
        for i in range(self.grid.size):
            for j in range(self.grid.size):
                self.grid.grid[i][j] = random.choice([0, 1])

    def run(self):
        while True:
            self.grid.update()

def main():
    sim = Simulation(10)
    sim.run()
main()