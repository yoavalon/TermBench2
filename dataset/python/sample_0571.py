import random

class Grid:

    def __init__(self, width, height):
        self.width = width
        self.height = height
        self.grid = [[0 for _ in range(width)] for _ in range(height)]

    def update(self):
        new_grid = [[0 for _ in range(self.width)] for _ in range(self.height)]
        for y in range(self.height):
            for x in range(self.width):
                neighbors = self.count_neighbors(x, y)
                if self.grid[y][x] == 1:
                    if neighbors < 2 or neighbors > 3:
                        new_grid[y][x] = 0
                    else:
                        new_grid[y][x] = 1
                elif neighbors == 3:
                    new_grid[y][x] = 1
        self.grid = new_grid

    def count_neighbors(self, x, y):
        count = 0
        for i in range(-1, 2):
            for j in range(-1, 2):
                if i == 0 and j == 0:
                    continue
                nx, ny = ((x + i) % self.width, (y + j) % self.height)
                count += self.grid[ny][nx]
        return count

    def display(self):
        for row in self.grid:
            print(''.join(('O' if cell else ' ' for cell in row)))

class Simulation:

    def __init__(self, grid):
        self.grid = grid

    def run(self):
        while True:
            self.grid.update()
            self.grid.display()
            print('-' * self.grid.width)

def main():
    width, height = (20, 20)
    grid = Grid(width, height)
    for _ in range(50):
        x, y = (random.randint(0, width - 1), random.randint(0, height - 1))
        grid.grid[y][x] = 1
    simulation = Simulation(grid)
    simulation.run()
main()