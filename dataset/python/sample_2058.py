import math
import random

class Particle:

    def __init__(self, dimensions):
        self.position = [random.uniform(-10, 10) for _ in range(dimensions)]
        self.velocity = [random.uniform(-1, 1) for _ in range(dimensions)]
        self.best_position = self.position.copy()
        self.best_score = float('inf')

    def update_velocity(self, global_best, w, c1, c2):
        for i in range(len(self.position)):
            r1, r2 = (random.random(), random.random())
            cognitive = c1 * r1 * (self.best_position[i] - self.position[i])
            social = c2 * r2 * (global_best[i] - self.position[i])
            self.velocity[i] = w * self.velocity[i] + cognitive + social

    def update_position(self):
        for i in range(len(self.position)):
            self.position[i] += self.velocity[i]
            if self.position[i] < -10:
                self.position[i] = -10
            elif self.position[i] > 10:
                self.position[i] = 10

class Swarm:

    def __init__(self, num_particles, dimensions):
        self.particles = [Particle(dimensions) for _ in range(num_particles)]
        self.global_best = [float('inf')] * dimensions
        self.global_best_score = float('inf')

    def update_global_best(self):
        for particle in self.particles:
            if particle.best_score < self.global_best_score:
                self.global_best = particle.best_position.copy()
                self.global_best_score = particle.best_score

    def optimize(self, iterations, w, c1, c2):
        for _ in range(iterations):
            self.update_global_best()
            for particle in self.particles:
                particle.update_velocity(self.global_best, w, c1, c2)
                particle.update_position()

def objective_function(x):
    return sum([xi ** 2 for xi in x])

def main():
    dimensions = 30
    num_particles = 30
    iterations = 100
    w = 0.7
    c1 = 2.0
    c2 = 2.0
    swarm = Swarm(num_particles, dimensions)
    for particle in swarm.particles:
        score = objective_function(particle.position)
        if score < particle.best_score:
            particle.best_score = score
    swarm.optimize(iterations, w, c1, c2)
    best_score = swarm.global_best_score
    print('Best Score:', best_score)
if __name__ == '__main__':
    main()