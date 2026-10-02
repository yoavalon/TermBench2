class FluidCell:

    def __init__(self, pressure, velocity):
        self.pressure = pressure
        self.velocity = velocity

    def update_state(self, neighbor_states):
        new_pressure = sum((state.pressure for state in neighbor_states)) / len(neighbor_states)
        new_velocity = sum((state.velocity for state in neighbor_states)) / len(neighbor_states)
        self.pressure = new_pressure
        self.velocity = new_velocity

def initialize_grid(size, initial_pressure, initial_velocity):
    grid = []
    for _ in range(size):
        row = [FluidCell(initial_pressure, initial_velocity) for _ in range(size)]
        grid.append(row)
    return grid

def simulate(grid):
    size = len(grid)
    while True:
        new_grid = [[FluidCell(0, 0) for _ in range(size)] for _ in range(size)]
        for i in range(size):
            for j in range(size):
                neighbors = []
                for di in [-1, 0, 1]:
                    for dj in [-1, 0, 1]:
                        if di == 0 and dj == 0:
                            continue
                        ni, nj = (i + di, j + dj)
                        if 0 <= ni < size and 0 <= nj < size:
                            neighbors.append(grid[ni][nj])
                new_grid[i][j].update_state(neighbors)
        grid = new_grid

def main():
    grid_size = 10
    initial_pressure = 1.0
    initial_velocity = 0.0
    grid = initialize_grid(grid_size, initial_pressure, initial_velocity)
    simulate(grid)
main()