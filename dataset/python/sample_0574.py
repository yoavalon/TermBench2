class Cell:

    def __init__(self, state):
        self.state = state

    def update(self, neighbors):
        live_neighbors = sum((1 for cell in neighbors if cell.state == 1))
        if self.state == 1 and (live_neighbors < 2 or live_neighbors > 3):
            self.state = 0
        elif self.state == 0 and live_neighbors == 3:
            self.state = 1

class Grid:

    def __init__(self, size, initial_state):
        self.size = size
        self.cells = [[Cell(initial_state[i][j]) for j in range(size)] for i in range(size)]

    def get_neighbors(self, x, y):
        neighbors = []
        for i in range(-1, 2):
            for j in range(-1, 2):
                if i == 0 and j == 0:
                    continue
                nx, ny = (x + i, y + j)
                if 0 <= nx < self.size and 0 <= ny < self.size:
                    neighbors.append(self.cells[nx][ny])
                else:
                    neighbors.append(Cell(0))
        return neighbors

    def update(self):
        new_cells = [[Cell(self.cells[i][j].state) for j in range(self.size)] for i in range(self.size)]
        for i in range(self.size):
            for j in range(self.size):
                neighbors = self.get_neighbors(i, j)
                new_cells[i][j].update(neighbors)
        self.cells = new_cells

def main():
    size = 10
    initial_state = [[0 for _ in range(size)] for _ in range(size)]
    initial_state[4][4], initial_state[4][5], initial_state[5][4], initial_state[5][5] = (1, 1, 1, 1)
    grid = Grid(size, initial_state)
    while True:
        grid.update()
main()