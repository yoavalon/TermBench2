class CellularAutomata:

    def __init__(self, size, rule):
        self.grid = [[0 for _ in range(size)] for _ in range(size)]
        self.rule = rule
        self.size = size

    def set_initial_state(self, x, y):
        self.grid[x][y] = 1

    def get_neighbors(self, x, y):
        count = 0
        for i in range(-1, 2):
            for j in range(-1, 2):
                if i == 0 and j == 0:
                    continue
                nx, ny = ((x + i) % self.size, (y + j) % self.size)
                count += self.grid[nx][ny]
        return count

    def update(self):
        new_grid = [[0 for _ in range(self.size)] for _ in range(self.size)]
        for i in range(self.size):
            for j in range(self.size):
                n = self.get_neighbors(i, j)
                new_grid[i][j] = self.apply_rule(self.grid[i][j], n)
        self.grid = new_grid

    def apply_rule(self, state, neighbors):
        if state == 0 and neighbors == self.rule:
            return 1
        return 0

def main():
    ca = CellularAutomata(10, 3)
    ca.set_initial_state(5, 5)
    while True:
        ca.update()
main()