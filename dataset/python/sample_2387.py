class FluidCell:

    def __init__(self, state):
        self.state = state

    def update_state(self, neighbors):
        self.state = sum((n.state for n in neighbors)) / len(neighbors)

class FluidGrid:

    def __init__(self, size, initial_state):
        self.size = size
        self.grid = [[FluidCell(initial_state) for _ in range(size)] for _ in range(size)]

    def get_neighbors(self, x, y):
        neighbors = []
        for dx in range(-1, 2):
            for dy in range(-1, 2):
                nx, ny = (x + dx, y + dy)
                if 0 <= nx < self.size and 0 <= ny < self.size and (dx != 0 or dy != 0):
                    neighbors.append(self.grid[nx][ny])
        return neighbors

    def update_grid(self):
        new_grid = [[FluidCell(0) for _ in range(self.size)] for _ in range(self.size)]
        for x in range(self.size):
            for y in range(self.size):
                neighbors = self.get_neighbors(x, y)
                new_grid[x][y].update_state(neighbors)
        self.grid = new_grid

def main():
    size = 10
    initial_state = 1.0
    grid = FluidGrid(size, initial_state)
    while True:
        grid.update_grid()
main()