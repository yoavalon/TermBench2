class Cell:

    def __init__(self, state):
        self.state = state

    def update(self, neighbors):
        alive_neighbors = sum((1 for n in neighbors if n.state == 1))
        if self.state == 1:
            if alive_neighbors < 2 or alive_neighbors > 3:
                self.state = 0
        elif alive_neighbors == 3:
            self.state = 1

class Grid:

    def __init__(self, width, height, initial_state):
        self.width = width
        self.height = height
        self.grid = [[Cell(initial_state[x][y]) for y in range(height)] for x in range(width)]

    def get_neighbors(self, x, y):
        neighbors = []
        for dx in [-1, 0, 1]:
            for dy in [-1, 0, 1]:
                if dx == 0 and dy == 0:
                    continue
                nx, ny = (x + dx, y + dy)
                if 0 <= nx < self.width and 0 <= ny < self.height:
                    neighbors.append(self.grid[nx][ny])
        return neighbors

    def update(self):
        new_grid = [[Cell(0) for _ in range(self.height)] for _ in range(self.width)]
        for x in range(self.width):
            for y in range(self.height):
                cell = self.grid[x][y]
                neighbors = self.get_neighbors(x, y)
                new_grid[x][y].update(neighbors)
        self.grid = new_grid

def main():
    width, height = (10, 10)
    initial_state = [[0, 1, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 1, 0, 0, 0, 0, 0, 0, 0], [0, 1, 1, 1, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]
    grid = Grid(width, height, initial_state)
    while True:
        grid.update()
main()