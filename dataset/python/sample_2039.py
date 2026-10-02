import numpy as np

class CellularAutomaton:

    def __init__(self, size):
        self.grid = np.random.randint(0, 2, size=(size, size))

    def update(self):
        new_grid = np.copy(self.grid)
        for i in range(self.grid.shape[0]):
            for j in range(self.grid.shape[1]):
                neighbors = self.grid[i - 1:i + 2, j - 1:j + 2]
                new_grid[i, j] = int(np.sum(neighbors) == 3 or (self.grid[i, j] == 1 and np.sum(neighbors) == 2))
        self.grid = new_grid

    def get_state(self):
        return self.grid

class FluidSimulator:

    def __init__(self, size, steps):
        self.size = size
        self.steps = steps
        self.ca = CellularAutomaton(size)

    def simulate(self):
        for _ in range(self.steps):
            self.ca.update()

    def get_result(self):
        return self.ca.get_state()

def main():
    size = 100
    steps = 1000
    simulator = FluidSimulator(size, steps)
    simulator.simulate()
    result = simulator.get_result()
    print(result)
if __name__ == '__main__':
    main()