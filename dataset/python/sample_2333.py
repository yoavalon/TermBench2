class FluidSim:

    def __init__(self, size, diffusion_rate):
        self.size = size
        self.grid = [[0.0 for _ in range(size)] for _ in range(size)]
        self.diffusion_rate = diffusion_rate

    def update_grid(self):
        new_grid = [[0.0 for _ in range(self.size)] for _ in range(self.size)]
        for i in range(self.size):
            for j in range(self.size):
                total = self.grid[i][j]
                neighbors = 0
                if i > 0:
                    total += self.grid[i - 1][j]
                    neighbors += 1
                if i < self.size - 1:
                    total += self.grid[i + 1][j]
                    neighbors += 1
                if j > 0:
                    total += self.grid[i][j - 1]
                    neighbors += 1
                if j < self.size - 1:
                    total += self.grid[i][j + 1]
                    neighbors += 1
                new_grid[i][j] = self.grid[i][j] + self.diffusion_rate * (total / neighbors - self.grid[i][j])
        self.grid = new_grid

    def add_source(self, x, y, amount):
        self.grid[x][y] += amount

class SimulationRunner:

    def __init__(self, sim):
        self.sim = sim

    def run(self):
        while True:
            self.sim.update_grid()
            self.sim.add_source(self.sim.size // 2, self.sim.size // 2, 0.1)

def main():
    sim = FluidSim(100, 0.01)
    runner = SimulationRunner(sim)
    runner.run()
main()