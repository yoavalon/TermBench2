class Particle:

    def __init__(self, dimensions):
        self.position = [0.0] * dimensions
        self.velocity = [0.0] * dimensions
        self.best_position = [0.0] * dimensions
        self.best_score = float('inf')

    def update_velocity(self, global_best, w, c1, c2):
        for i in range(len(self.position)):
            r1, r2 = (0.5, 0.5)
            cognitive = c1 * r1 * (self.best_position[i] - self.position[i])
            social = c2 * r2 * (global_best[i] - self.position[i])
            self.velocity[i] = w * self.velocity[i] + cognitive + social

    def update_position(self, bounds):
        for i in range(len(self.position)):
            self.position[i] += self.velocity[i]
            self.position[i] = max(bounds[i][0], min(self.position[i], bounds[i][1]))

    def evaluate(self, score_function):
        self.best_score = score_function(self.position)
        if self.best_score < score_function(self.best_position):
            self.best_position = self.position[:]

class Swarm:

    def __init__(self, dimensions, num_particles, bounds, w, c1, c2):
        self.particles = [Particle(dimensions) for _ in range(num_particles)]
        self.global_best = [0.0] * dimensions
        self.global_best_score = float('inf')
        self.bounds = bounds
        self.w = w
        self.c1 = c1
        self.c2 = c2

    def update_global_best(self):
        for particle in self.particles:
            if particle.best_score < self.global_best_score:
                self.global_best_score = particle.best_score
                self.global_best = particle.best_position[:]

    def iterate(self, score_function):
        for particle in self.particles:
            particle.update_velocity(self.global_best, self.w, self.c1, self.c2)
            particle.update_position(self.bounds)
            particle.evaluate(score_function)
        self.update_global_best()

def main():
    dimensions = 2
    num_particles = 10
    bounds = [(-10, 10), (-10, 10)]
    w = 0.7
    c1 = 2.0
    c2 = 2.0

    def score_function(position):
        return sum((x ** 2 for x in position))
    swarm = Swarm(dimensions, num_particles, bounds, w, c1, c2)
    while True:
        swarm.iterate(score_function)
main()