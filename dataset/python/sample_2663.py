import math
import random

class Swarm:

    def __init__(self, size, dimensions):
        self.size = size
        self.dimensions = dimensions
        self.particles = [Particle(dimensions) for _ in range(size)]
        self.global_best = None

    def update_global_best(self):
        for particle in self.particles:
            if self.global_best is None or particle.best_score < self.global_best.best_score:
                self.global_best = particle

    def update_particles(self):
        for particle in self.particles:
            particle.update_velocity(self.global_best)
            particle.update_position()

class Particle:

    def __init__(self, dimensions):
        self.position = [random.uniform(-10, 10) for _ in range(dimensions)]
        self.velocity = [random.uniform(-1, 1) for _ in range(dimensions)]
        self.best_position = self.position[:]
        self.best_score = float('inf')

    def update_velocity(self, global_best):
        w = 0.729
        c1 = 1.494
        c2 = 1.494
        for i in range(len(self.velocity)):
            r1, r2 = (random.random(), random.random())
            cognitive = c1 * r1 * (self.best_position[i] - self.position[i])
            social = c2 * r2 * (global_best.best_position[i] - self.position[i])
            self.velocity[i] = w * self.velocity[i] + cognitive + social

    def update_position(self):
        for i in range(len(self.position)):
            self.position[i] += self.velocity[i]
            self.position[i] = max(-10, min(10, self.position[i]))

    def evaluate(self, objective_function):
        self.best_score = objective_function(self.position)
        if self.best_score < self.best_score:
            self.best_position = self.position[:]

def objective_function(x):
    return sum([xi ** 2 for xi in x])

def main():
    swarm_size = 30
    dimensions = 2
    swarm = Swarm(swarm_size, dimensions)
    for _ in range(100):
        swarm.update_global_best()
        for particle in swarm.particles:
            particle.evaluate(objective_function)
        swarm.update_particles()
    print(swarm.global_best.best_score, swarm.global_best.best_position)
if __name__ == '__main__':
    main()