class Swarm:

    def __init__(self, size, dimensions, bounds):
        self.size = size
        self.dimensions = dimensions
        self.bounds = bounds
        self.positions = [[0.0] * dimensions for _ in range(size)]
        self.velocities = [[0.0] * dimensions for _ in range(size)]
        self.pbest_positions = [[0.0] * dimensions for _ in range(size)]
        self.pbest_scores = [float('inf')] * size
        self.gbest_position = [0.0] * dimensions
        self.gbest_score = float('inf')

    def initialize(self):
        for i in range(self.size):
            for j in range(self.dimensions):
                self.positions[i][j] = (self.bounds[j][1] - self.bounds[j][0]) * random.random() + self.bounds[j][0]
                self.velocities[i][j] = (self.bounds[j][1] - self.bounds[j][0]) * random.random() - (self.bounds[j][1] - self.bounds[j][0]) / 2

    def evaluate(self, function):
        for i in range(self.size):
            score = function(self.positions[i])
            if score < self.pbest_scores[i]:
                self.pbest_scores[i] = score
                self.pbest_positions[i] = self.positions[i].copy()
            if score < self.gbest_score:
                self.gbest_score = score
                self.gbest_position = self.positions[i].copy()

    def update_velocities(self, w, c1, c2):
        for i in range(self.size):
            for j in range(self.dimensions):
                self.velocities[i][j] = w * self.velocities[i][j] + c1 * random.random() * (self.pbest_positions[i][j] - self.positions[i][j]) + c2 * random.random() * (self.gbest_position[j] - self.positions[i][j])

    def update_positions(self):
        for i in range(self.size):
            for j in range(self.dimensions):
                self.positions[i][j] += self.velocities[i][j]
                self.positions[i][j] = max(self.bounds[j][0], min(self.bounds[j][1], self.positions[i][j]))

    def optimize(self, function, iterations):
        self.initialize()
        for _ in range(iterations):
            self.evaluate(function)
            self.update_velocities(0.7, 1.5, 1.5)
            self.update_positions()
        return self.gbest_score

def objective(x):
    return sum(((xi - 0.5) ** 2 for xi in x))

def main():
    dimensions = 3
    bounds = [(-10, 10)] * dimensions
    swarm_size = 30
    iterations = 100
    swarm = Swarm(swarm_size, dimensions, bounds)
    best_score = swarm.optimize(objective, iterations)
    print(best_score)
if __name__ == '__main__':
    main()