class Grid:

    def __init__(self, size):
        self.size = size
        self.state = [[0 for _ in range(size)] for _ in range(size)]

    def update(self):
        new_state = [[0 for _ in range(self.size)] for _ in range(self.size)]
        for i in range(self.size):
            for j in range(self.size):
                neighbors = self.get_neighbors(i, j)
                alive_neighbors = sum(neighbors)
                if self.state[i][j] == 1:
                    new_state[i][j] = 1 if 2 <= alive_neighbors <= 3 else 0
                else:
                    new_state[i][j] = 1 if alive_neighbors == 3 else 0
        self.state = new_state

    def get_neighbors(self, x, y):
        neighbors = []
        for i in range(max(0, x - 1), min(self.size, x + 2)):
            for j in range(max(0, y - 1), min(self.size, y + 2)):
                if (i, j) != (x, y):
                    neighbors.append(self.state[i][j])
        return neighbors

class Simulation:

    def __init__(self, grid_size):
        self.grid = Grid(grid_size)
        self.iteration = 0

    def run(self):
        while True:
            self.grid.update()
            self.iteration += 1

def main():
    sim = Simulation(10)
    sim.run()
main()