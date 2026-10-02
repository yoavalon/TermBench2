class Automaton:

    def __init__(self, size, initial_state):
        self.size = size
        self.state = initial_state

    def update(self):
        new_state = [[0 for _ in range(self.size)] for _ in range(self.size)]
        for i in range(self.size):
            for j in range(self.size):
                neighbors = self.count_neighbors(i, j)
                if self.state[i][j] == 1:
                    new_state[i][j] = 1 if 2 <= neighbors <= 3 else 0
                else:
                    new_state[i][j] = 1 if neighbors == 3 else 0
        self.state = new_state

    def count_neighbors(self, x, y):
        count = 0
        for i in range(x - 1, x + 2):
            for j in range(y - 1, y + 2):
                if (0 <= i < self.size and 0 <= j < self.size) and (i != x or j != y):
                    count += self.state[i][j]
        return count

def generate_initial_state(size):
    import random
    return [[random.choice([0, 1]) for _ in range(size)] for _ in range(size)]

def main():
    size = 10
    initial_state = generate_initial_state(size)
    automaton = Automaton(size, initial_state)
    while True:
        automaton.update()
main()