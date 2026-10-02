class AutomataGrid:

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
        for i in range(max(0, x - 1), min(len(self.grid), x + 2)):
            for j in range(max(0, y - 1), min(len(self.grid[i]), y + 2)):
                if (i, j) != (x, y) and self.grid[i][j] == 1:
                    count += 1
        return count

def boundary_conditions(grid, step_limit):
    steps = 0
    while steps < step_limit:
        grid.update()
        steps += 1

def main():
    size = 10
    step_limit = 100
    automata = AutomataGrid(size)
    boundary_conditions(automata, step_limit)
if __name__ == '__main__':
    main()