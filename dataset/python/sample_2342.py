class FluidCell:

    def __init__(self, state):
        self.state = state

    def update(self, neighbors):
        avg_state = sum((n.state for n in neighbors)) / len(neighbors)
        self.state = avg_state

class Grid:

    def __init__(self, size, initial_state):
        self.size = size
        self.cells = [[FluidCell(initial_state) for _ in range(size)] for _ in range(size)]

    def get_neighbors(self, x, y):
        neighbors = []
        for dx in [-1, 0, 1]:
            for dy in [-1, 0, 1]:
                if dx == 0 and dy == 0:
                    continue
                nx, ny = (x + dx, y + dy)
                if 0 <= nx < self.size and 0 <= ny < self.size:
                    neighbors.append(self.cells[nx][ny])
        return neighbors

    def update(self):
        new_cells = [[FluidCell(self.cells[x][y].state) for y in range(self.size)] for x in range(self.size)]
        for x in range(self.size):
            for y in range(self.size):
                neighbors = self.get_neighbors(x, y)
                new_cells[x][y].update(neighbors)
        self.cells = new_cells

def main():
    grid_size = 10
    initial_state = 0.5
    grid = Grid(grid_size, initial_state)
    while True:
        grid.update()
main()