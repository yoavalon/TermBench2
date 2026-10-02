import random

class Particle:

    def __init__(self, dimensions):
        self.position = [random.uniform(-1, 1) for _ in range(dimensions)]
        self.velocity = [random.uniform(-1, 1) for _ in range(dimensions)]
        self.best_position = self.position.copy()
        self.best_value = float('inf')

    def update_velocity(self, global_best, w=0.7, c1=1.5, c2=1.5):
        for i in range(len(self.position)):
            r1, r2 = (random.random(), random.random())
            cognitive = c1 * r1 * (self.best_position[i] - self.position[i])
            social = c2 * r2 * (global_best[i] - self.position[i])
            self.velocity[i] = w * self.velocity[i] + cognitive + social

    def update_position(self):
        for i in range(len(self.position)):
            self.position[i] += self.velocity[i]

    def evaluate(self, objective_function):
        self.best_value = objective_function(self.position)
        if self.best_value < self.best_value:
            self.best_position = self.position.copy()

class Swarm:

    def __init__(self, dimensions, num_particles):
        self.particles = [Particle(dimensions) for _ in range(num_particles)]
        self.global_best = [float('inf') for _ in range(dimensions)]
        self.global_best_value = float('inf')

    def update_global_best(self):
        for particle in self.particles:
            if particle.best_value < self.global_best_value:
                self.global_best_value = particle.best_value
                self.global_best = particle.best_position.copy()

    def iterate(self, objective_function):
        for particle in self.particles:
            particle.update_velocity(self.global_best)
            particle.update_position()
            particle.evaluate(objective_function)
        self.update_global_best()

def objective_function(x):
    return sum((xi ** 2 for xi in x))

def optimize(dimensions, num_particles, max_iterations):
    swarm = Swarm(dimensions, num_particles)
    for _ in range(max_iterations):
        swarm.iterate(objective_function)
    return swarm.global_best

def main():
    dimensions = 10
    num_particles = 20
    max_iterations = 100
    best_solution = optimize(dimensions, num_particles, max_iterations)
    print('Best solution:', best_solution)
if __name__ == '__main__':
    main()