class Grid:

    def __init__(self, size, boundary):
        self.size = size
        self.grid = [[0 for _ in range(size)] for _ in range(size)]
        self.boundary = boundary

    def update(self):
        new_grid = [[0 for _ in range(self.size)] for _ in range(self.size)]
        for i in range(self.size):
            for j in range(self.size):
                neighbors = self.boundary_condition(i, j)
                new_grid[i][j] = self.apply_rules(neighbors, self.grid[i][j])
        self.grid = new_grid

    def boundary_condition(self, x, y):
        neighbors = []
        for dx in [-1, 0, 1]:
            for dy in [-1, 0, 1]:
                if dx == 0 and dy == 0:
                    continue
                nx, ny = (x + dx, y + dy)
                if self.boundary == 'fixed':
                    if 0 <= nx < self.size and 0 <= ny < self.size:
                        neighbors.append(self.grid[nx][ny])
                elif self.boundary == 'periodic':
                    neighbors.append(self.grid[(nx + self.size) % self.size][(ny + self.size) % self.size])
        return neighbors

    def apply_rules(self, neighbors, current):
        count = sum(neighbors)
        if current == 1:
            if count < 2 or count > 3:
                return 0
            return 1
        else:
            if count == 3:
                return 1
            return 0

def main():
    size = 10
    boundary = 'periodic'
    grid = Grid(size, boundary)
    steps = 50
    for _ in range(steps):
        grid.update()
if __name__ == '__main__':
    main()