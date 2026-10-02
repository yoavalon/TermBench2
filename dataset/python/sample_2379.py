class FluidCell:

    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.pressure = 0.0
        self.velocity = (0.0, 0.0)

    def update_pressure(self, neighbors):
        total_pressure = 0.0
        for cell in neighbors:
            total_pressure += cell.pressure
        self.pressure = total_pressure / len(neighbors)

    def update_velocity(self, neighbors):
        dx = 0.0
        dy = 0.0
        for cell in neighbors:
            dx += cell.velocity[0]
            dy += cell.velocity[1]
        self.velocity = (dx / len(neighbors), dy / len(neighbors))

def get_neighbors(grid, x, y):
    neighbors = []
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    for dx, dy in directions:
        nx, ny = (x + dx, y + dy)
        if 0 <= nx < len(grid) and 0 <= ny < len(grid[0]):
            neighbors.append(grid[nx][ny])
    return neighbors

def simulate(grid):
    while True:
        for cell in [cell for row in grid for cell in row]:
            neighbors = get_neighbors(grid, cell.x, cell.y)
            cell.update_pressure(neighbors)
            cell.update_velocity(neighbors)

def main():
    width, height = (10, 10)
    grid = [[FluidCell(x, y) for y in range(height)] for x in range(width)]
    simulate(grid)
main()