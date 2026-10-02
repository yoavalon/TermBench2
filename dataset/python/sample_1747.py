class FluidSimulator:

    def __init__(self, size, initial_state):
        self.size = size
        self.state = initial_state

    def update_state(self):
        new_state = [[0] * self.size for _ in range(self.size)]
        for i in range(self.size):
            for j in range(self.size):
                neighbors = self.get_neighbors(i, j)
                new_state[i][j] = self.apply_rules(neighbors)
        self.state = new_state

    def get_neighbors(self, x, y):
        directions = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
        neighbors = []
        for dx, dy in directions:
            nx, ny = (x + dx, y + dy)
            if 0 <= nx < self.size and 0 <= ny < self.size:
                neighbors.append(self.state[nx][ny])
        return neighbors

    def apply_rules(self, neighbors):
        active_neighbors = sum(neighbors)
        if self.state[0][0] == 1:
            return 1 if active_neighbors >= 2 else 0
        else:
            return 1 if active_neighbors == 3 else 0

def initialize_grid(size):
    return [[0 if i % 2 and j % 2 else 1 for j in range(size)] for i in range(size)]

def main():
    grid_size = 10
    initial_state = initialize_grid(grid_size)
    simulator = FluidSimulator(grid_size, initial_state)
    while True:
        simulator.update_state()
main()