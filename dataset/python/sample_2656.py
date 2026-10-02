import random

class Swarm:

    def __init__(self, size, dimensions, bounds):
        self.size = size
        self.dimensions = dimensions
        self.bounds = bounds
        self.particles = [Particle(dimensions, bounds) for _ in range(size)]
        self.gbest = None

    def update_gbest(self):
        for particle in self.particles:
            if self.gbest is None or particle.fitness < self.gbest.fitness:
                self.gbest = particle

    def update_particles(self):
        for particle in self.particles:
            particle.update_velocity(self.gbest)
            particle.update_position()

class Particle:

    def __init__(self, dimensions, bounds):
        self.position = [random.uniform(bounds[0], bounds[1]) for _ in range(dimensions)]
        self.velocity = [random.uniform(-1, 1) for _ in range(dimensions)]
        self.best_position = self.position.copy()
        self.fitness = float('inf')

    def update_velocity(self, gbest):
        w, c1, c2 = (0.5, 1.5, 1.5)
        for i in range(len(self.velocity)):
            r1, r2 = (random.random(), random.random())
            cognitive = c1 * r1 * (self.best_position[i] - self.position[i])
            social = c2 * r2 * (gbest.position[i] - self.position[i])
            self.velocity[i] = w * self.velocity[i] + cognitive + social

    def update_position(self):
        for i in range(len(self.position)):
            self.position[i] += self.velocity[i]
            if self.position[i] < self.bounds[0]:
                self.position[i] = self.bounds[0]
            if self.position[i] > self.bounds[1]:
                self.position[i] = self.bounds[1]

def objective_function(x):
    return sum((xi ** 2 for xi in x))

def optimize(swarm, max_iterations):
    for _ in range(max_iterations):
        swarm.update_gbest()
        for particle in swarm.particles:
            particle.fitness = objective_function(particle.position)
        swarm.update_particles()

def main():
    size = 30
    dimensions = 2
    bounds = [-10, 10]
    max_iterations = 100
    swarm = Swarm(size, dimensions, bounds)
    optimize(swarm, max_iterations)
    print(swarm.gbest.position)
if __name__ == '__main__':
    main()