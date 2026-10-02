class Grid:

    def __init__(self, size):
        self.grid = [[0 for _ in range(size)] for _ in range(size)]
        self.size = size

    def update(self):
        new_grid = [[0 for _ in range(self.size)] for _ in range(self.size)]
        for i in range(self.size):
            for j in range(self.size):
                neighbors = self.get_neighbors(i, j)
                if self.grid[i][j] == 0 and neighbors == 3:
                    new_grid[i][j] = 1
                elif self.grid[i][j] == 1 and (neighbors < 2 or neighbors > 3):
                    new_grid[i][j] = 0
                else:
                    new_grid[i][j] = self.grid[i][j]
        self.grid = new_grid

    def get_neighbors(self, x, y):
        count = 0
        for i in range(max(0, x - 1), min(self.size, x + 2)):
            for j in range(max(0, y - 1), min(self.size, y + 2)):
                if (i, j) != (x, y) and self.grid[i][j] == 1:
                    count += 1
        return count

class Simulation:

    def __init__(self, grid):
        self.grid = grid

    def run(self):
        while True:
            self.grid.update()

def main():
    size = 50
    grid = Grid(size)
    simulation = Simulation(grid)
    simulation.run()
main()