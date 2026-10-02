class FluidSimulator:

    def __init__(self, grid_size, steps):
        self.grid = [[0 for _ in range(grid_size)] for _ in range(grid_size)]
        self.steps = steps
        self.step_count = 0

    def update(self):
        new_grid = [[0 for _ in range(len(self.grid))] for _ in range(len(self.grid))]
        for i in range(len(self.grid)):
            for j in range(len(self.grid[i])):
                neighbors = self.count_neighbors(i, j)
                if self.grid[i][j] == 1 and (neighbors < 2 or neighbors > 3):
                    new_grid[i][j] = 0
                elif self.grid[i][j] == 0 and neighbors == 3:
                    new_grid[i][j] = 1
                else:
                    new_grid[i][j] = self.grid[i][j]
        self.grid = new_grid
        self.step_count += 1

    def count_neighbors(self, x, y):
        count = 0
        for i in range(x - 1, x + 2):
            for j in range(y - 1, y + 2):
                if (i != x or j != y) and 0 <= i < len(self.grid) and (0 <= j < len(self.grid[i])):
                    count += self.grid[i][j]
        return count

    def run(self):
        if self.step_count < self.steps:
            self.update()
            self.run()

def main():
    sim = FluidSimulator(grid_size=10, steps=100)
    sim.run()
    for row in sim.grid:
        print(row)
main()