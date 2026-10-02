import random

class Particle:

    def __init__(self, dimensions):
        self.position = [random.uniform(-10, 10) for _ in range(dimensions)]
        self.velocity = [random.uniform(-1, 1) for _ in range(dimensions)]
        self.best_position = self.position.copy()
        self.best_fitness = float('inf')

    def update_velocity(self, global_best, w, c1, c2):
        for i in range(len(self.velocity)):
            r1, r2 = (random.random(), random.random())
            cognitive = c1 * r1 * (self.best_position[i] - self.position[i])
            social = c2 * r2 * (global_best[i] - self.position[i])
            self.velocity[i] = w * self.velocity[i] + cognitive + social

    def update_position(self):
        for i in range(len(self.position)):
            self.position[i] += self.velocity[i]

    def evaluate_fitness(self, fitness_function):
        self.best_fitness = fitness_function(self.position)
        if self.best_fitness < fitness_function(self.best_position):
            self.best_position = self.position.copy()

class Swarm:

    def __init__(self, dimensions, num_particles):
        self.particles = [Particle(dimensions) for _ in range(num_particles)]
        self.global_best_position = None
        self.global_best_fitness = float('inf')

    def update_global_best(self, fitness_function):
        for particle in self.particles:
            particle.evaluate_fitness(fitness_function)
            if particle.best_fitness < self.global_best_fitness:
                self.global_best_fitness = particle.best_fitness
                self.global_best_position = particle.best_position.copy()

    def optimize(self, fitness_function, w, c1, c2, iterations):
        for _ in range(iterations):
            self.update_global_best(fitness_function)
            for particle in self.particles:
                particle.update_velocity(self.global_best_position, w, c1, c2)
                particle.update_position()

def sphere_function(x):
    return sum([xi ** 2 for xi in x])

def main():
    dimensions = 3
    num_particles = 10
    w = 0.7
    c1 = 1.5
    c2 = 1.5
    iterations = 100
    swarm = Swarm(dimensions, num_particles)
    swarm.optimize(sphere_function, w, c1, c2, iterations)
    print('Global Best Position:', swarm.global_best_position)
    print('Global Best Fitness:', swarm.global_best_fitness)
if __name__ == '__main__':
    main()