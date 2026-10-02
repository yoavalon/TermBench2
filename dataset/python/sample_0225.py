import random
import math

class PSOSettings:

    def __init__(self, dimensions, population_size, max_iterations):
        self.dimensions = dimensions
        self.population_size = population_size
        self.max_iterations = max_iterations
        self.c1 = 2.0
        self.c2 = 2.0
        self.w = 0.7

class Particle:

    def __init__(self, dimensions, lower_bound, upper_bound):
        self.position = [random.uniform(lower_bound, upper_bound) for _ in range(dimensions)]
        self.velocity = [random.uniform(-1, 1) for _ in range(dimensions)]
        self.best_position = self.position[:]
        self.best_fitness = float('inf')

def fitness(position):
    return sum((x ** 2 for x in position))

def update_velocity(particle, global_best, settings):
    for i in range(settings.dimensions):
        r1, r2 = (random.random(), random.random())
        cognitive = settings.c1 * r1 * (particle.best_position[i] - particle.position[i])
        social = settings.c2 * r2 * (global_best[i] - particle.position[i])
        particle.velocity[i] = settings.w * particle.velocity[i] + cognitive + social

def update_position(particle, settings):
    for i in range(settings.dimensions):
        particle.position[i] += particle.velocity[i]
        if particle.position[i] < -10:
            particle.position[i] = -10
        elif particle.position[i] > 10:
            particle.position[i] = 10

def optimize(settings):
    population = [Particle(settings.dimensions, -10, 10) for _ in range(settings.population_size)]
    global_best = [0] * settings.dimensions
    global_best_fitness = float('inf')
    for iteration in range(settings.max_iterations):
        for particle in population:
            current_fitness = fitness(particle.position)
            if current_fitness < particle.best_fitness:
                particle.best_fitness = current_fitness
                particle.best_position = particle.position[:]
            if current_fitness < global_best_fitness:
                global_best_fitness = current_fitness
                global_best = particle.position[:]
        for particle in population:
            update_velocity(particle, global_best, settings)
            update_position(particle, settings)
    return (global_best, global_best_fitness)

def main():
    settings = PSOSettings(dimensions=2, population_size=30, max_iterations=100)
    best_position, best_fitness = optimize(settings)
    print('Best position:', best_position)
    print('Best fitness:', best_fitness)
main()