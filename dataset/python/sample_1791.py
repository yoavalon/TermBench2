class Cell:

    def __init__(self, state=0):
        self.state = state

    def update(self, neighbors):
        live_neighbors = sum((1 for cell in neighbors if cell.state == 1))
        if self.state == 1:
            self.state = 1 if live_neighbors in (2, 3) else 0
        else:
            self.state = 1 if live_neighbors == 3 else 0

class Grid:

    def __init__(self, width, height, initial_state=None):
        self.width = width
        self.height = height
        self.grid = [[Cell(initial_state[i][j]) if initial_state else Cell() for j in range(width)] for i in range(height)]

    def get_neighbors(self, x, y):
        directions = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
        neighbors = []
        for dx, dy in directions:
            nx, ny = (x + dx, y + dy)
            if 0 <= nx < self.width and 0 <= ny < self.height:
                neighbors.append(self.grid[ny][nx])
        return neighbors

    def update(self):
        new_grid = [[Cell(self.grid[i][j].state) for j in range(self.width)] for i in range(self.height)]
        for i in range(self.height):
            for j in range(self.width):
                neighbors = self.get_neighbors(j, i)
                new_grid[i][j].update(neighbors)
        self.grid = new_grid

def main():
    initial_state = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]
    grid = Grid(3, 3, initial_state)
    while True:
        grid.update()
main()