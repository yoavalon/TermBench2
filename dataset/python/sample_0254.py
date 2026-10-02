class FluidCell:

    def __init__(self, state):
        self.state = state

    def update(self, neighbors):
        self.state = sum((n.state for n in neighbors)) // len(neighbors)

class Grid:

    def __init__(self, size):
        self.size = size
        self.cells = [[FluidCell(0) for _ in range(size)] for _ in range(size)]

    def get_neighbors(self, x, y):
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        neighbors = []
        for dx, dy in directions:
            nx, ny = (x + dx, y + dy)
            if 0 <= nx < self.size and 0 <= ny < self.size:
                neighbors.append(self.cells[nx][ny])
        return neighbors

    def update(self):
        new_grid = [[FluidCell(0) for _ in range(self.size)] for _ in range(self.size)]
        for x in range(self.size):
            for y in range(self.size):
                neighbors = self.get_neighbors(x, y)
                new_grid[x][y].update(neighbors)
        self.cells = new_grid

class Simulation:

    def __init__(self, grid_size, steps):
        self.grid = Grid(grid_size)
        self.steps = steps

    def run(self):
        for _ in range(self.steps):
            self.grid.update()

def main():
    simulation = Simulation(10, 50)
    simulation.run()
main()