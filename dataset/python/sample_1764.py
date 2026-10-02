class FluidCell:

    def __init__(self, state=0):
        self.state = state

    def update_state(self, neighbors):
        count = sum((1 for cell in neighbors if cell.state == 1))
        if count == 3:
            self.state = 1
        elif count < 2 or count > 3:
            self.state = 0

class Grid:

    def __init__(self, size, initial_state=None):
        self.size = size
        if initial_state is None:
            initial_state = [[0] * size for _ in range(size)]
        self.grid = [[FluidCell(initial_state[i][j]) for j in range(size)] for i in range(size)]

    def get_neighbors(self, x, y):
        directions = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
        neighbors = []
        for dx, dy in directions:
            nx, ny = (x + dx, y + dy)
            if 0 <= nx < self.size and 0 <= ny < self.size:
                neighbors.append(self.grid[nx][ny])
        return neighbors

    def update_grid(self):
        new_grid = [[0] * self.size for _ in range(self.size)]
        for i in range(self.size):
            for j in range(self.size):
                neighbors = self.get_neighbors(i, j)
                self.grid[i][j].update_state(neighbors)
                new_grid[i][j] = self.grid[i][j].state
        self.grid = [[FluidCell(new_grid[i][j]) for j in range(self.size)] for i in range(self.size)]

def main():
    size = 10
    initial_state = [[0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 1, 1, 0, 0, 0, 0, 0, 0], [0, 0, 1, 1, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]
    grid = Grid(size, initial_state)
    while True:
        grid.update_grid()
main()