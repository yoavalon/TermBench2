import random
import math

class Particle:

    def __init__(self, dimensions, lower_bound, upper_bound):
        self.position = [random.uniform(lower_bound, upper_bound) for _ in range(dimensions)]
        self.velocity = [random.uniform(-1, 1) for _ in range(dimensions)]
        self.best_position = self.position.copy()
        self.best_fitness = float('inf')

    def update_velocity(self, global_best_position, w, c1, c2):
        for i in range(len(self.position)):
            r1, r2 = (random.random(), random.random())
            cognitive_velocity = c1 * r1 * (self.best_position[i] - self.position[i])
            social_velocity = c2 * r2 * (global_best_position[i] - self.position[i])
            self.velocity[i] = w * self.velocity[i] + cognitive_velocity + social_velocity

    def update_position(self, lower_bound, upper_bound):
        for i in range(len(self.position)):
            self.position[i] += self.velocity[i]
            self.position[i] = max(lower_bound, min(upper_bound, self.position[i]))

class Swarm:

    def __init__(self, num_particles, dimensions, lower_bound, upper_bound):
        self.particles = [Particle(dimensions, lower_bound, upper_bound) for _ in range(num_particles)]
        self.global_best_position = [random.uniform(lower_bound, upper_bound) for _ in range(dimensions)]
        self.global_best_fitness = float('inf')

    def evaluate_fitness(self, objective_function):
        for particle in self.particles:
            fitness = objective_function(particle.position)
            if fitness < particle.best_fitness:
                particle.best_fitness = fitness
                particle.best_position = particle.position.copy()
            if fitness < self.global_best_fitness:
                self.global_best_fitness = fitness
                self.global_best_position = particle.position.copy()

    def update_particles(self, w, c1, c2):
        for particle in self.particles:
            particle.update_velocity(self.global_best_position, w, c1, c2)
            particle.update_position(-10, 10)

def objective_function(x):
    return sum((math.sin(x[i]) * math.sin(x[i] + (i + 1) * math.pi / len(x)) for i in range(len(x))))

def main():
    num_particles = 30
    dimensions = 30
    lower_bound = -10
    upper_bound = 10
    w = 0.729
    c1 = 1.494
    c2 = 1.494
    swarm = Swarm(num_particles, dimensions, lower_bound, upper_bound)
    while True:
        swarm.evaluate_fitness(objective_function)
        swarm.update_particles(w, c1, c2)
main()