class Grid:

    def __init__(self, size):
        self.grid = [[0 for _ in range(size)] for _ in range(size)]

    def update(self):
        new_grid = [[0 for _ in range(len(self.grid))] for _ in range(len(self.grid))]
        for i in range(len(self.grid)):
            for j in range(len(self.grid[i])):
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
        for i in range(x - 1, x + 2):
            for j in range(y - 1, y + 2):
                if (i != x or j != y) and 0 <= i < len(self.grid) and (0 <= j < len(self.grid[i])):
                    count += self.grid[i][j]
        return count

class Simulation:

    def __init__(self, grid_size):
        self.grid = Grid(grid_size)

    def run(self):
        while True:
            self.grid.update()

def main():
    simulation = Simulation(10)
    simulation.run()
main()