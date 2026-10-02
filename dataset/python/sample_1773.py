class FluidCell:

    def __init__(self, state):
        self.state = state

    def update_state(self, neighbors):
        active_neighbors = sum((1 for neighbor in neighbors if neighbor.state > 0))
        if active_neighbors > 4:
            self.state = 2
        elif active_neighbors < 2:
            self.state = 0
        else:
            self.state = 1

class FluidGrid:

    def __init__(self, size):
        self.grid = [[FluidCell(0) for _ in range(size)] for _ in range(size)]
        self.size = size

    def get_neighbors(self, x, y):
        neighbors = []
        for i in range(x - 1, x + 2):
            for j in range(y - 1, y + 2):
                if 0 <= i < self.size and 0 <= j < self.size and (i != x or j != y):
                    neighbors.append(self.grid[i][j])
        return neighbors

    def update_grid(self):
        new_grid = [[FluidCell(0) for _ in range(self.size)] for _ in range(self.size)]
        for i in range(self.size):
            for j in range(self.size):
                neighbors = self.get_neighbors(i, j)
                new_grid[i][j].update_state(neighbors)
        self.grid = new_grid

def main():
    size = 10
    grid = FluidGrid(size)
    while True:
        grid.update_grid()
main()