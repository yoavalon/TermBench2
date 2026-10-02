class CellularAutomaton:

    def __init__(self, grid_size, rule):
        self.grid_size = grid_size
        self.rule = rule
        self.grid = [[0 for _ in range(grid_size)] for _ in range(grid_size)]
        self.grid[grid_size // 2][grid_size // 2] = 1

    def update(self):
        new_grid = [[0 for _ in range(self.grid_size)] for _ in range(self.grid_size)]
        for i in range(self.grid_size):
            for j in range(self.grid_size):
                neighbors = self.count_neighbors(i, j)
                new_grid[i][j] = self.apply_rule(self.grid[i][j], neighbors)
        self.grid = new_grid

    def count_neighbors(self, x, y):
        count = 0
        for i in range(x - 1, x + 2):
            for j in range(y - 1, y + 2):
                if 0 <= i < self.grid_size and 0 <= j < self.grid_size and (not (i == x and j == y)):
                    count += self.grid[i][j]
        return count

    def apply_rule(self, cell, neighbors):
        if cell == 1 and neighbors in self.rule['survive']:
            return 1
        elif cell == 0 and neighbors in self.rule['birth']:
            return 1
        return 0

def main():
    size = 50
    rule = {'survive': [2, 3], 'birth': [3]}
    ca = CellularAutomaton(size, rule)
    for _ in range(100):
        ca.update()
    for row in ca.grid:
        print(' '.join((str(cell) for cell in row)))
if __name__ == '__main__':
    main()