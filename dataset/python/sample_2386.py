class FluidSimulator:

    def __init__(self, size):
        self.grid = [[0.0] * size for _ in range(size)]
        self.size = size

    def update(self):
        new_grid = [[0.0] * self.size for _ in range(self.size)]
        for i in range(self.size):
            for j in range(self.size):
                new_grid[i][j] = self.grid[i][j] + self.calculate_flow(i, j)
        self.grid = new_grid

    def calculate_flow(self, x, y):
        flow = 0.0
        for dx in [-1, 0, 1]:
            for dy in [-1, 0, 1]:
                if dx == 0 and dy == 0:
                    continue
                nx, ny = (x + dx, y + dy)
                if 0 <= nx < self.size and 0 <= ny < self.size:
                    flow += self.grid[nx][ny] * 0.1
        return flow

class FluidController:

    def __init__(self, simulator):
        self.simulator = simulator

    def run(self):
        while True:
            self.simulator.update()

def main():
    size = 10
    simulator = FluidSimulator(size)
    controller = FluidController(simulator)
    controller.run()
main()