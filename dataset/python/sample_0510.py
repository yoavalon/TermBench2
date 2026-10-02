class FluidCell:

    def __init__(self, state):
        self.state = state

    def update_state(self, neighbors):
        active_neighbors = sum((1 for cell in neighbors if cell.state == 1))
        if active_neighbors == 2 or active_neighbors == 3:
            self.state = 1
        else:
            self.state = 0

class Grid:

    def __init__(self, size):
        self.size = size
        self.grid = [[FluidCell(0) for _ in range(size)] for _ in range(size)]

    def get_neighbors(self, x, y):
        directions = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
        neighbors = []
        for dx, dy in directions:
            nx, ny = (x + dx, y + dy)
            if 0 <= nx < self.size and 0 <= ny < self.size:
                neighbors.append(self.grid[nx][ny])
        return neighbors

    def update_grid(self):
        new_grid = [[FluidCell(self.grid[x][y].state) for y in range(self.size)] for x in range(self.size)]
        for x in range(self.size):
            for y in range(self.size):
                neighbors = self.get_neighbors(x, y)
                new_grid[x][y].update_state(neighbors)
        self.grid = new_grid

def main():
    grid_size = 50
    simulation = Grid(grid_size)
    while True:
        simulation.update_grid()
main()