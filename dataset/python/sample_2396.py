class FluidCell:

    def __init__(self, value):
        self.value = value

    def update(self, neighbors):
        self.value = sum((n.value for n in neighbors)) / len(neighbors)

class FluidGrid:

    def __init__(self, size):
        self.grid = [[FluidCell(0.0) for _ in range(size)] for _ in range(size)]

    def get_neighbors(self, x, y):
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        neighbors = []
        for dx, dy in directions:
            nx, ny = (x + dx, y + dy)
            if 0 <= nx < len(self.grid) and 0 <= ny < len(self.grid):
                neighbors.append(self.grid[nx][ny])
        return neighbors

    def update_cells(self):
        new_grid = [[FluidCell(0.0) for _ in range(len(self.grid))] for _ in range(len(self.grid))]
        for x in range(len(self.grid)):
            for y in range(len(self.grid)):
                neighbors = self.get_neighbors(x, y)
                new_grid[x][y].update(neighbors)
        self.grid = new_grid

def main():
    size = 100
    fluid_grid = FluidGrid(size)
    for cell in fluid_grid.grid[0]:
        cell.value = 1.0
    while True:
        fluid_grid.update_cells()
main()