class Swarm:

    def __init__(self, size, dimensions):
        self.size = size
        self.dimensions = dimensions
        self.positions = [[0.0 for _ in range(dimensions)] for _ in range(size)]
        self.velocities = [[0.0 for _ in range(dimensions)] for _ in range(size)]
        self.best_positions = [[0.0 for _ in range(dimensions)] for _ in range(size)]
        self.best_scores = [float('inf') for _ in range(size)]
        self.global_best_position = [0.0 for _ in range(dimensions)]
        self.global_best_score = float('inf')

    def update_global_best(self):
        for i in range(self.size):
            score = self.evaluate(self.best_positions[i])
            if score < self.global_best_score:
                self.global_best_score = score
                self.global_best_position = self.best_positions[i]

    def evaluate(self, position):
        return sum((x ** 2 for x in position))

    def update_particles(self):
        for i in range(self.size):
            for j in range(self.dimensions):
                r1, r2 = (0.5, 0.5)
                c1, c2 = (2.0, 2.0)
                self.velocities[i][j] = 0.7 * self.velocities[i][j] + c1 * r1 * (self.best_positions[i][j] - self.positions[i][j]) + c2 * r2 * (self.global_best_position[j] - self.positions[i][j])
                self.positions[i][j] += self.velocities[i][j]
            self.best_scores[i] = self.evaluate(self.positions[i])
            if self.best_scores[i] < self.global_best_score:
                self.best_positions[i] = self.positions[i]

    def iterate(self):
        self.update_global_best()
        self.update_particles()
        self.iterate()

def main():
    swarm = Swarm(30, 2)
    swarm.iterate()
main()