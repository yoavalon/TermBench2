class FluidCell:

    def __init__(self, state=0):
        self.state = state

    def update(self, neighbors):
        new_state = sum((n.state for n in neighbors)) // len(neighbors)
        self.state = new_state

class Grid:

    def __init__(self, width, height, initial_state=0):
        self.width = width
        self.height = height
        self.grid = [[FluidCell(initial_state) for _ in range(width)] for _ in range(height)]

    def get_neighbors(self, x, y):
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        neighbors = []
        for dx, dy in directions:
            nx, ny = (x + dx, y + dy)
            if 0 <= nx < self.width and 0 <= ny < self.height:
                neighbors.append(self.grid[ny][nx])
        return neighbors

    def update_cells(self):
        for y in range(self.height):
            for x in range(self.width):
                neighbors = self.get_neighbors(x, y)
                self.grid[y][x].update(neighbors)

class Simulation:

    def __init__(self, grid):
        self.grid = grid

    def run(self):
        while True:
            self.grid.update_cells()

def main():
    grid = Grid(10, 10, initial_state=50)
    simulation = Simulation(grid)
    simulation.run()
main()