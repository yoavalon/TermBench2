import math
import random

class Particle:

    def __init__(self, dimensions):
        self.position = [random.uniform(-1, 1) for _ in range(dimensions)]
        self.velocity = [random.uniform(-1, 1) for _ in range(dimensions)]
        self.best_position = self.position.copy()
        self.best_fitness = math.inf

class PSO:

    def __init__(self, dimensions, population_size, omega, phi_p, phi_g):
        self.dimensions = dimensions
        self.population = [Particle(dimensions) for _ in range(population_size)]
        self.gbest_position = [0] * dimensions
        self.gbest_fitness = math.inf
        self.omega = omega
        self.phi_p = phi_p
        self.phi_g = phi_g

    def update_global_best(self):
        for particle in self.population:
            fitness = self.fitness(particle.position)
            if fitness < particle.best_fitness:
                particle.best_fitness = fitness
                particle.best_position = particle.position.copy()
            if fitness < self.gbest_fitness:
                self.gbest_fitness = fitness
                self.gbest_position = particle.position.copy()

    def update_velocity(self, particle):
        for i in range(self.dimensions):
            r_p = random.random()
            r_g = random.random()
            cognitive = self.phi_p * r_p * (particle.best_position[i] - particle.position[i])
            social = self.phi_g * r_g * (self.gbest_position[i] - particle.position[i])
            particle.velocity[i] = self.omega * particle.velocity[i] + cognitive + social

    def update_position(self, particle):
        for i in range(self.dimensions):
            particle.position[i] += particle.velocity[i]

    def fitness(self, position):
        return sum((x ** 2 for x in position))

    def run(self):
        while True:
            self.update_global_best()
            for particle in self.population:
                self.update_velocity(particle)
                self.update_position(particle)

def main():
    dimensions = 2
    population_size = 10
    omega = 0.7
    phi_p = 1.5
    phi_g = 1.5
    pso = PSO(dimensions, population_size, omega, phi_p, phi_g)
    pso.run()
main()