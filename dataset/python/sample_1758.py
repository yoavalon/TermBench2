class FluidSimulator:

    def __init__(self, grid_size):
        self.grid = [[0] * grid_size for _ in range(grid_size)]
        self.size = grid_size

    def update(self):
        new_grid = [[0] * self.size for _ in range(self.size)]
        for x in range(self.size):
            for y in range(self.size):
                neighbors = self.get_neighbors(x, y)
                if self.grid[x][y] == 1:
                    if sum(neighbors) < 2 or sum(neighbors) > 3:
                        new_grid[x][y] = 0
                    else:
                        new_grid[x][y] = 1
                elif sum(neighbors) == 3:
                    new_grid[x][y] = 1
        self.grid = new_grid

    def get_neighbors(self, x, y):
        neighbors = []
        for dx in [-1, 0, 1]:
            for dy in [-1, 0, 1]:
                if dx == 0 and dy == 0:
                    continue
                nx, ny = (x + dx, y + dy)
                if 0 <= nx < self.size and 0 <= ny < self.size:
                    neighbors.append(self.grid[nx][ny])
        return neighbors

    def display(self):
        for row in self.grid:
            print(''.join(['#' if cell == 1 else ' ' for cell in row]))

def main():
    simulator = FluidSimulator(10)
    simulator.grid[4][4] = 1
    simulator.grid[5][4] = 1
    simulator.grid[4][5] = 1
    simulator.grid[5][5] = 1
    while True:
        simulator.display()
        simulator.update()
main()