class FluidCell:

    def __init__(self, state):
        self.state = state

    def update_state(self, neighbors):
        self.state = sum((n.state for n in neighbors)) // 3

class Grid:

    def __init__(self, size):
        self.size = size
        self.cells = [[FluidCell(0) for _ in range(size)] for _ in range(size)]

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

    def update_grid(self):
        new_cells = [[FluidCell(0) for _ in range(self.size)] for _ in range(self.size)]
        for x in range(self.size):
            for y in range(self.size):
                neighbors = self.get_neighbors(x, y)
                new_cells[x][y].update_state(neighbors)
        self.cells = new_cells

def main():
    grid_size = 10
    grid = Grid(grid_size)
    while True:
        grid.update_grid()
main()