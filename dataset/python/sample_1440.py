class Grid:

    def __init__(self, size):
        self.grid = [[0 for _ in range(size)] for _ in range(size)]
        self.size = size

    def update(self):
        new_grid = [[0 for _ in range(self.size)] for _ in range(self.size)]
        for i in range(self.size):
            for j in range(self.size):
                neighbors = self.count_neighbors(i, j)
                if self.grid[i][j] == 1 and (neighbors < 2 or neighbors > 3):
                    new_grid[i][j] = 0
                elif self.grid[i][j] == 0 and neighbors == 3:
                    new_grid[i][j] = 1
                else:
                    new_grid[i][j] = self.grid[i][j]
        self.grid = new_grid

    def count_neighbors(self, x, y):
        count = 0
        for i in range(x - 1, x + 2):
            for j in range(y - 1, y + 2):
                if (i != x or j != y) and 0 <= i < self.size and (0 <= j < self.size):
                    count += self.grid[i][j]
        return count

class Simulation:

    def __init__(self, grid):
        self.grid = grid
        self.steps = 0

    def run(self, max_steps):
        while self.steps < max_steps:
            self.grid.update()
            self.steps += 1

def main():
    size = 50
    max_steps = 100
    grid = Grid(size)
    simulation = Simulation(grid)
    simulation.run(max_steps)
if __name__ == '__main__':
    main()