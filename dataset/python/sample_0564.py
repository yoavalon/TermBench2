class FluidSimulator:

    def __init__(self, grid_size):
        self.grid = [[0 for _ in range(grid_size)] for _ in range(grid_size)]
        self.size = grid_size

    def update(self):
        new_grid = [[0 for _ in range(self.size)] for _ in range(self.size)]
        for i in range(self.size):
            for j in range(self.size):
                new_grid[i][j] = self.apply_rules(i, j)
        self.grid = new_grid

    def apply_rules(self, x, y):
        neighbors = self.get_neighbors(x, y)
        count = sum(neighbors)
        if self.grid[x][y] == 1:
            return 1 if count > 1 else 0
        else:
            return 1 if count == 3 else 0

    def get_neighbors(self, x, y):
        directions = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
        neighbors = []
        for dx, dy in directions:
            nx, ny = ((x + dx) % self.size, (y + dy) % self.size)
            neighbors.append(self.grid[nx][ny])
        return neighbors

class BoundaryConditionApplier:

    def __init__(self, simulator):
        self.simulator = simulator

    def apply(self):
        for i in range(self.simulator.size):
            self.simulator.grid[i][0] = 1
            self.simulator.grid[i][-1] = 1
            self.simulator.grid[0][i] = 1
            self.simulator.grid[-1][i] = 1

def main():
    grid_size = 10
    simulator = FluidSimulator(grid_size)
    boundary_conditions = BoundaryConditionApplier(simulator)
    while True:
        boundary_conditions.apply()
        simulator.update()
main()