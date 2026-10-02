class AutomataSimulator:

    def __init__(self, size, rule):
        self.grid = [[0 for _ in range(size)] for _ in range(size)]
        self.rule = rule
        self.size = size

    def update(self):
        new_grid = [[0 for _ in range(self.size)] for _ in range(self.size)]
        for i in range(self.size):
            for j in range(self.size):
                state = self.grid[i][j]
                neighbors = self.count_neighbors(i, j)
                new_state = self.apply_rule(state, neighbors)
                new_grid[i][j] = new_state
        self.grid = new_grid

    def count_neighbors(self, x, y):
        count = 0
        for i in range(x - 1, x + 2):
            for j in range(y - 1, y + 2):
                if 0 <= i < self.size and 0 <= j < self.size and (not (i == x and j == y)):
                    count += self.grid[i][j]
        return count

    def apply_rule(self, state, neighbors):
        return self.rule[state][neighbors]

def main():
    size = 10
    rule = {0: {0: 0, 1: 1, 2: 1, 3: 1, 4: 0, 5: 0, 6: 0, 7: 0, 8: 0}, 1: {0: 0, 1: 0, 2: 0, 3: 1, 4: 0, 5: 0, 6: 0, 7: 0, 8: 0}}
    automata = AutomataSimulator(size, rule)
    for _ in range(100):
        automata.update()
    print(automata.grid)
if __name__ == '__main__':
    main()