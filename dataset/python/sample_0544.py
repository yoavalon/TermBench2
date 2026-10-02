class Grid:

    def __init__(self, size):
        self.size = size
        self.state = [[0 for _ in range(size)] for _ in range(size)]

    def update(self):
        new_state = [[0 for _ in range(self.size)] for _ in range(self.size)]
        for i in range(self.size):
            for j in range(self.size):
                neighbors = self.get_neighbors(i, j)
                if self.state[i][j] == 0 and neighbors == 3:
                    new_state[i][j] = 1
                elif self.state[i][j] == 1 and (neighbors < 2 or neighbors > 3):
                    new_state[i][j] = 0
                else:
                    new_state[i][j] = self.state[i][j]
        self.state = new_state

    def get_neighbors(self, x, y):
        count = 0
        for i in range(max(0, x - 1), min(x + 2, self.size)):
            for j in range(max(0, y - 1), min(y + 2, self.size)):
                if (i, j) != (x, y) and self.state[i][j] == 1:
                    count += 1
        return count

def display(grid):
    for row in grid.state:
        print(''.join(['*' if cell else ' ' for cell in row]))
    print()

def main():
    size = 10
    grid = Grid(size)
    for i in range(size):
        for j in range(size):
            if i % 2 == 0 and j % 2 == 0:
                grid.state[i][j] = 1
    while True:
        display(grid)
        grid.update()
main()