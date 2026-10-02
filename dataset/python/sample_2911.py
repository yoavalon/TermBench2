import random

class AutomatonCell:

    def __init__(self, state):
        self.state = state

    def update_state(self, neighbors):
        alive_neighbors = sum((1 for cell in neighbors if cell.state == 1))
        if self.state == 1:
            if alive_neighbors < 2 or alive_neighbors > 3:
                self.state = 0
        elif alive_neighbors == 3:
            self.state = 1

class AutomatonGrid:

    def __init__(self, size):
        self.grid = [[AutomatonCell(random.randint(0, 1)) for _ in range(size)] for _ in range(size)]

    def get_neighbors(self, x, y):
        size = len(self.grid)
        neighbors = []
        for i in range(-1, 2):
            for j in range(-1, 2):
                if i == 0 and j == 0:
                    continue
                nx, ny = (x + i, y + j)
                if 0 <= nx < size and 0 <= ny < size:
                    neighbors.append(self.grid[nx][ny])
        return neighbors

    def update_grid(self):
        new_grid = [[AutomatonCell(0) for _ in range(len(self.grid))] for _ in range(len(self.grid))]
        for x in range(len(self.grid)):
            for y in range(len(self.grid)):
                neighbors = self.get_neighbors(x, y)
                new_grid[x][y].update_state(neighbors)
        self.grid = new_grid

def simulate():
    size = 50
    grid = AutomatonGrid(size)
    while True:
        grid.update_grid()
simulate()