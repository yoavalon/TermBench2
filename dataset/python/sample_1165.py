class FluidGrid:

    def __init__(self, size):
        self.grid = [[0 for _ in range(size)] for _ in range(size)]
        self.size = size

    def update(self):
        new_grid = [[0 for _ in range(self.size)] for _ in range(self.size)]
        for i in range(self.size):
            for j in range(self.size):
                new_grid[i][j] = self.calculate_next_state(i, j)
        self.grid = new_grid

    def calculate_next_state(self, x, y):
        neighbors = self.get_neighbors(x, y)
        count = sum(neighbors)
        if self.grid[x][y] == 0:
            return 1 if count > 2 else 0
        else:
            return 1 if count in [2, 3] else 0

    def get_neighbors(self, x, y):
        directions = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
        neighbors = []
        for dx, dy in directions:
            nx, ny = (x + dx, y + dy)
            if 0 <= nx < self.size and 0 <= ny < self.size:
                neighbors.append(self.grid[nx][ny])
            else:
                neighbors.append(0)
        return neighbors

def main():
    size = 10
    grid = FluidGrid(size)
    while True:
        grid.update()
main()