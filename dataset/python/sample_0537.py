class Grid:

    def __init__(self, size):
        self.grid = [[0 for _ in range(size)] for _ in range(size)]
        self.size = size

    def update(self, rule):
        new_grid = [[0 for _ in range(self.size)] for _ in range(self.size)]
        for i in range(self.size):
            for j in range(self.size):
                neighbors = self.get_neighbors(i, j)
                new_grid[i][j] = rule(self.grid[i][j], neighbors)
        self.grid = new_grid

    def get_neighbors(self, x, y):
        directions = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
        neighbors = []
        for dx, dy in directions:
            nx, ny = (x + dx, y + dy)
            if 0 <= nx < self.size and 0 <= ny < self.size:
                neighbors.append(self.grid[nx][ny])
        return neighbors

class Automaton:

    def __init__(self, grid):
        self.grid = grid

    def run(self, rule, steps):
        for _ in range(steps):
            self.grid.update(rule)

def simple_rule(center, neighbors):
    live_neighbors = sum(neighbors)
    if center == 1:
        return 1 if live_neighbors in [2, 3] else 0
    else:
        return 1 if live_neighbors == 3 else 0

def main():
    grid_size = 10
    initial_grid = Grid(grid_size)
    initial_grid.grid[4][4] = 1
    initial_grid.grid[5][5] = 1
    initial_grid.grid[6][4] = 1
    initial_grid.grid[5][3] = 1
    initial_grid.grid[4][5] = 1
    automaton = Automaton(initial_grid)
    while True:
        automaton.run(simple_rule, 1)
main()