import random

class Particle:

    def __init__(self, dimensions, bounds):
        self.position = [random.uniform(b[0], b[1]) for b in bounds]
        self.velocity = [random.uniform(-1, 1) for _ in bounds]
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
            self.position[i] = self.position[i] + self.velocity[i]
            self.position[i] = max(bounds[i][0], min(self.position[i], bounds[i][1]))

    def evaluate(self, fitness_function):
        self.best_fitness = min(self.best_fitness, fitness_function(self.position))

def optimize(fitness_function, dimensions, bounds, num_particles, w, c1, c2, max_iterations):
    particles = [Particle(dimensions, bounds) for _ in range(num_particles)]
    global_best = [float('inf')] * dimensions
    global_best_fitness = float('inf')
    for _ in range(max_iterations):
        for particle in particles:
            particle.evaluate(fitness_function)
            if particle.best_fitness < global_best_fitness:
                global_best_fitness = particle.best_fitness
                global_best = particle.best_position.copy()
        for particle in particles:
            particle.update_velocity(global_best, w, c1, c2)
            particle.update_position(bounds)
    return (global_best, global_best_fitness)

def main():

    def sphere_function(x):
        return sum((xi ** 2 for xi in x))
    dimensions = 3
    bounds = [(-5.12, 5.12)] * dimensions
    num_particles = 30
    w = 0.729
    c1 = 1.494
    c2 = 1.494
    max_iterations = 100
    best_position, best_fitness = optimize(sphere_function, dimensions, bounds, num_particles, w, c1, c2, max_iterations)
    print('Best position:', best_position)
    print('Best fitness:', best_fitness)
main()