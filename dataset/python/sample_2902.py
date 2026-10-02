import random

class Particle:

    def __init__(self, dimensions):
        self.position = [random.uniform(-1, 1) for _ in range(dimensions)]
        self.velocity = [random.uniform(-1, 1) for _ in range(dimensions)]
        self.best_position = self.position.copy()
        self.best_fitness = float('inf')

    def update_velocity(self, global_best, w, c1, c2):
        for i in range(len(self.position)):
            r1, r2 = (random.random(), random.random())
            cognitive = c1 * r1 * (self.best_position[i] - self.position[i])
            social = c2 * r2 * (global_best[i] - self.position[i])
            self.velocity[i] = w * self.velocity[i] + cognitive + social

    def update_position(self, bounds):
        for i in range(len(self.position)):
            self.position[i] += self.velocity[i]
            self.position[i] = max(bounds[0][i], min(bounds[1][i], self.position[i]))

    def evaluate_fitness(self, fitness_function):
        self.fitness = fitness_function(self.position)
        if self.fitness < self.best_fitness:
            self.best_fitness = self.fitness
            self.best_position = self.position.copy()

class Swarm:

    def __init__(self, num_particles, dimensions, bounds, fitness_function):
        self.particles = [Particle(dimensions) for _ in range(num_particles)]
        self.global_best = [random.uniform(-1, 1) for _ in range(dimensions)]
        self.global_best_fitness = float('inf')
        self.fitness_function = fitness_function
        self.bounds = bounds

    def update_global_best(self):
        for particle in self.particles:
            if particle.best_fitness < self.global_best_fitness:
                self.global_best_fitness = particle.best_fitness
                self.global_best = particle.best_position.copy()

    def optimize(self, w, c1, c2):
        while True:
            for particle in self.particles:
                particle.update_velocity(self.global_best, w, c1, c2)
                particle.update_position(self.bounds)
                particle.evaluate_fitness(self.fitness_function)
            self.update_global_best()

def fitness_function(x):
    return sum((xi ** 2 for xi in x))

def main():
    dimensions = 2
    num_particles = 30
    bounds = ((-10, -10), (10, 10))
    swarm = Swarm(num_particles, dimensions, bounds, fitness_function)
    w = 0.729
    c1 = 1.494
    c2 = 1.494
    swarm.optimize(w, c1, c2)
main()