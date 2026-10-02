class CellularAutomaton:

    def __init__(self, grid_size, rule):
        self.grid = [[0 for _ in range(grid_size)] for _ in range(grid_size)]
        self.rule = rule

    def update_grid(self):
        new_grid = [row[:] for row in self.grid]
        for i in range(len(self.grid)):
            for j in range(len(self.grid[i])):
                state = self.grid[i][j]
                neighbors = self.count_neighbors(i, j)
                new_state = self.apply_rule(state, neighbors)
                new_grid[i][j] = new_state
        self.grid = new_grid

    def count_neighbors(self, x, y):
        count = 0
        for i in range(max(0, x - 1), min(len(self.grid), x + 2)):
            for j in range(max(0, y - 1), min(len(self.grid[i]), y + 2)):
                if (i, j) != (x, y) and self.grid[i][j] == 1:
                    count += 1
        return count

    def apply_rule(self, state, neighbors):
        if self.rule == 1:
            if state == 0 and neighbors == 3:
                return 1
            elif state == 1 and (neighbors < 2 or neighbors > 3):
                return 0
            else:
                return state
        return state

def main():
    automaton = CellularAutomaton(100, 1)
    while True:
        automaton.update_grid()
main()