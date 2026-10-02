class Swarm:

    def __init__(self, size, dimensions):
        self.size = size
        self.dimensions = dimensions
        self.particles = [[0.0] * dimensions for _ in range(size)]
        self.velocities = [[0.0] * dimensions for _ in range(size)]
        self.best_positions = [[0.0] * dimensions for _ in range(size)]
        self.best_scores = [float('inf')] * size
        self.global_best = [0.0] * dimensions
        self.global_best_score = float('inf')

    def update_global_best(self):
        for i in range(self.size):
            if self.best_scores[i] < self.global_best_score:
                self.global_best_score = self.best_scores[i]
                self.global_best = self.best_positions[i]

    def update_particles(self):
        for i in range(self.size):
            for j in range(self.dimensions):
                r1, r2 = (0.5, 0.5)
                cognitive = r1 * (self.best_positions[i][j] - self.particles[i][j])
                social = r2 * (self.global_best[j] - self.particles[i][j])
                self.velocities[i][j] += cognitive + social
                self.particles[i][j] += self.velocities[i][j]

    def evaluate(self, objective_function):
        for i in range(self.size):
            score = objective_function(self.particles[i])
            if score < self.best_scores[i]:
                self.best_scores[i] = score
                self.best_positions[i] = self.particles[i].copy()
        self.update_global_best()

class Optimization:

    def __init__(self, swarm, objective_function):
        self.swarm = swarm
        self.objective_function = objective_function

    def run(self):
        while True:
            self.swarm.update_particles()
            self.swarm.evaluate(self.objective_function)

def objective_function(position):
    return sum((x ** 2 for x in position))

def main():
    size = 30
    dimensions = 2
    swarm = Swarm(size, dimensions)
    optimization = Optimization(swarm, objective_function)
    optimization.run()
main()