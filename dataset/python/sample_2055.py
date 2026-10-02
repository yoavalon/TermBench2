import random
import math

class Particle:

    def __init__(self, dimensions):
        self.position = [random.uniform(-10, 10) for _ in range(dimensions)]
        self.velocity = [random.uniform(-1, 1) for _ in range(dimensions)]
        self.best_position = self.position[:]
        self.best_score = float('inf')

class Swarm:

    def __init__(self, num_particles, dimensions):
        self.particles = [Particle(dimensions) for _ in range(num_particles)]
        self.global_best_position = [0.0] * dimensions
        self.global_best_score = float('inf')

    def update_global_best(self):
        for particle in self.particles:
            score = self.evaluate(particle.position)
            if score < self.global_best_score:
                self.global_best_score = score
                self.global_best_position = particle.position[:]

    def evaluate(self, position):
        return sum((x ** 2 for x in position))

    def update_particles(self, w, c1, c2):
        for particle in self.particles:
            for i in range(len(particle.position)):
                r1, r2 = (random.random(), random.random())
                particle.velocity[i] = w * particle.velocity[i] + c1 * r1 * (particle.best_position[i] - particle.position[i]) + c2 * r2 * (self.global_best_position[i] - particle.position[i])
                particle.position[i] += particle.velocity[i]
                particle.best_score = min(particle.best_score, self.evaluate(particle.position))
                particle.best_position = particle.position[:] if particle.best_score < self.evaluate(particle.best_position) else particle.best_position[:]

def main():
    dimensions = 30
    num_particles = 30
    w = 0.7
    c1 = 1.5
    c2 = 1.5
    iterations = 100
    swarm = Swarm(num_particles, dimensions)
    for _ in range(iterations):
        swarm.update_global_best()
        swarm.update_particles(w, c1, c2)
    print('Best score:', swarm.global_best_score)
if __name__ == '__main__':
    main()