import random
import math

class Particle:

    def __init__(self, dimensions):
        self.position = [random.uniform(-10, 10) for _ in range(dimensions)]
        self.velocity = [random.uniform(-1, 1) for _ in range(dimensions)]
        self.best_position = self.position.copy()
        self.best_score = float('inf')

class Swarm:

    def __init__(self, num_particles, dimensions):
        self.particles = [Particle(dimensions) for _ in range(num_particles)]
        self.gbest_position = None
        self.gbest_score = float('inf')

    def update_gbest(self):
        for particle in self.particles:
            if particle.best_score < self.gbest_score:
                self.gbest_score = particle.best_score
                self.gbest_position = particle.best_position.copy()

    def update_particles(self, w, c1, c2):
        for particle in self.particles:
            for i in range(len(particle.position)):
                r1, r2 = (random.random(), random.random())
                particle.velocity[i] = w * particle.velocity[i] + c1 * r1 * (particle.best_position[i] - particle.position[i]) + c2 * r2 * (self.gbest_position[i] - particle.position[i])
                particle.position[i] += particle.velocity[i]

    def evaluate(self, objective_function):
        for particle in self.particles:
            score = objective_function(particle.position)
            if score < particle.best_score:
                particle.best_score = score
                particle.best_position = particle.position.copy()

def objective_function(x):
    return sum((xi ** 2 for xi in x))

def main():
    dimensions = 3
    num_particles = 20
    w = 0.7
    c1 = 1.5
    c2 = 1.5
    iterations = 100
    swarm = Swarm(num_particles, dimensions)
    for _ in range(iterations):
        swarm.update_gbest()
        swarm.update_particles(w, c1, c2)
        swarm.evaluate(objective_function)
    print('Best score:', swarm.gbest_score)
    print('Best position:', swarm.gbest_position)
if __name__ == '__main__':
    main()