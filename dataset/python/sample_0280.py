class Grid:

    def __init__(self, size):
        self.size = size
        self.data = [[0 for _ in range(size)] for _ in range(size)]

    def update(self):
        new_data = [[0 for _ in range(self.size)] for _ in range(self.size)]
        for i in range(self.size):
            for j in range(self.size):
                new_data[i][j] = self._calculate_next_state(i, j)
        self.data = new_data

    def _calculate_next_state(self, i, j):
        neighbors = self._get_neighbors(i, j)
        alive_count = sum(neighbors)
        if self.data[i][j] == 1:
            return 1 if alive_count in [2, 3] else 0
        else:
            return 1 if alive_count == 3 else 0

    def _get_neighbors(self, i, j):
        neighbors = []
        for x in range(max(0, i - 1), min(self.size, i + 2)):
            for y in range(max(0, j - 1), min(self.size, j + 2)):
                if (x, y) != (i, j):
                    neighbors.append(self.data[x][y])
        return neighbors

def main():
    grid_size = 10
    grid = Grid(grid_size)
    steps = 50
    for _ in range(steps):
        grid.update()
if __name__ == '__main__':
    main()