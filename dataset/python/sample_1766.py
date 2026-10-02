class FluidSimulator:

    def __init__(self, grid_size, rules):
        self.grid = [[0 for _ in range(grid_size)] for _ in range(grid_size)]
        self.rules = rules

    def update(self):
        new_grid = [[0 for _ in range(len(self.grid))] for _ in range(len(self.grid))]
        for i in range(len(self.grid)):
            for j in range(len(self.grid)):
                new_grid[i][j] = self.rules.apply(self.grid, i, j)
        self.grid = new_grid

    def display(self):
        for row in self.grid:
            print(' '.join(map(str, row)))
        print()

class RuleSet:

    def apply(self, grid, x, y):
        neighbors = self.count_neighbors(grid, x, y)
        return 1 if neighbors == 2 else 0

    def count_neighbors(self, grid, x, y):
        count = 0
        for i in range(max(0, x - 1), min(len(grid), x + 2)):
            for j in range(max(0, y - 1), min(len(grid), y + 2)):
                if (i, j) != (x, y) and grid[i][j] == 1:
                    count += 1
        return count

def main():
    grid_size = 10
    rules = RuleSet()
    simulator = FluidSimulator(grid_size, rules)
    simulator.grid[4][4] = 1
    simulator.grid[5][4] = 1
    simulator.grid[4][5] = 1
    while True:
        simulator.display()
        simulator.update()
main()