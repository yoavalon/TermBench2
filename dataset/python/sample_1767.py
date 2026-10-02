class Grid:

    def __init__(self, size, initial_state):
        self.size = size
        self.state = initial_state

    def update(self):
        new_state = [[0 for _ in range(self.size)] for _ in range(self.size)]
        for i in range(self.size):
            for j in range(self.size):
                neighbors = self.count_neighbors(i, j)
                if self.state[i][j] == 1 and (neighbors == 2 or neighbors == 3):
                    new_state[i][j] = 1
                elif self.state[i][j] == 0 and neighbors == 3:
                    new_state[i][j] = 1
        self.state = new_state

    def count_neighbors(self, x, y):
        count = 0
        for i in range(max(0, x - 1), min(self.size, x + 2)):
            for j in range(max(0, y - 1), min(self.size, y + 2)):
                if (i != x or j != y) and self.state[i][j] == 1:
                    count += 1
        return count

def generate_initial_state(size, density):
    import random
    return [[random.randint(0, 1) if random.random() < density else 0 for _ in range(size)] for _ in range(size)]

def main():
    size = 100
    density = 0.2
    grid = Grid(size, generate_initial_state(size, density))
    while True:
        grid.update()
main()