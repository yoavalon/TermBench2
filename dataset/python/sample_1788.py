class Grid:

    def __init__(self, size):
        self.size = size
        self.state = [[0 for _ in range(size)] for _ in range(size)]

    def update(self):
        new_state = [[0 for _ in range(self.size)] for _ in range(self.size)]
        for i in range(self.size):
            for j in range(self.size):
                neighbors = self.count_neighbors(i, j)
                if self.state[i][j] == 0:
                    if neighbors == 3:
                        new_state[i][j] = 1
                elif neighbors in [2, 3]:
                    new_state[i][j] = 1
        self.state = new_state

    def count_neighbors(self, x, y):
        count = 0
        for i in range(max(0, x - 1), min(self.size, x + 2)):
            for j in range(max(0, y - 1), min(self.size, y + 2)):
                if (i, j) != (x, y) and self.state[i][j] == 1:
                    count += 1
        return count

def display(grid):
    for row in grid.state:
        print(''.join(('O' if cell == 1 else '.' for cell in row)))
    print()

def main():
    size = 50
    grid = Grid(size)
    for i in range(size):
        for j in range(size):
            grid.state[i][j] = 1 if (i + j) % 2 == 0 else 0
    while True:
        display(grid)
        grid.update()
main()