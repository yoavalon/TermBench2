import random
import math

class Particle:

    def __init__(self, dimensions):
        self.position = [random.uniform(-1, 1) for _ in range(dimensions)]
        self.velocity = [random.uniform(-1, 1) for _ in range(dimensions)]
        self.best_position = self.position.copy()
        self.best_score = float('inf')

    def update_velocity(self, global_best, inertia, cognitive, social):
        for i in range(len(self.position)):
            r1 = random.random()
            r2 = random.random()
            self.velocity[i] = inertia * self.velocity[i] + cognitive * r1 * (self.best_position[i] - self.position[i]) + social * r2 * (global_best[i] - self.position[i])

    def update_position(self):
        for i in range(len(self.position)):
            self.position[i] += self.velocity[i]

    def evaluate(self, fitness_function):
        self.score = fitness_function(self.position)
        if self.score < self.best_score:
            self.best_score = self.score
            self.best_position = self.position.copy()

class Swarm:

    def __init__(self, size, dimensions, fitness_function, max_iterations, inertia, cognitive, social):
        self.particles = [Particle(dimensions) for _ in range(size)]
        self.fitness_function = fitness_function
        self.max_iterations = max_iterations
        self.inertia = inertia
        self.cognitive = cognitive
        self.social = social
        self.global_best = None
        self.global_best_score = float('inf')

    def update_global_best(self):
        for particle in self.particles:
            if particle.best_score < self.global_best_score:
                self.global_best_score = particle.best_score
                self.global_best = particle.best_position.copy()

    def optimize(self):
        for _ in range(self.max_iterations):
            for particle in self.particles:
                particle.update_velocity(self.global_best, self.inertia, self.cognitive, self.social)
                particle.update_position()
                particle.evaluate(self.fitness_function)
            self.update_global_best()

def sphere_function(x):
    return sum((xi ** 2 for xi in x))

def main():
    dimensions = 2
    size = 30
    max_iterations = 100
    inertia = 0.5
    cognitive = 1.5
    social = 1.5
    swarm = Swarm(size, dimensions, sphere_function, max_iterations, inertia, cognitive, social)
    swarm.optimize()
    print('Best position:', swarm.global_best)
    print('Best score:', swarm.global_best_score)
if __name__ == '__main__':
    main()