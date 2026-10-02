import random

class Particle:

    def __init__(self, dimensions):
        self.position = [random.uniform(-10, 10) for _ in range(dimensions)]
        self.velocity = [random.uniform(-1, 1) for _ in range(dimensions)]
        self.best_position = self.position.copy()

    def update_velocity(self, global_best, inertia, cognitive, social):
        for i in range(len(self.velocity)):
            r1, r2 = (random.random(), random.random())
            self.velocity[i] = inertia * self.velocity[i] + cognitive * r1 * (self.best_position[i] - self.position[i]) + social * r2 * (global_best[i] - self.position[i])

    def update_position(self):
        for i in range(len(self.position)):
            self.position[i] += self.velocity[i]

    def update_best_position(self, objective_function):
        current_fitness = objective_function(self.position)
        best_fitness = objective_function(self.best_position)
        if current_fitness < best_fitness:
            self.best_position = self.position.copy()

class Swarm:

    def __init__(self, dimensions, num_particles, objective_function):
        self.particles = [Particle(dimensions) for _ in range(num_particles)]
        self.global_best = self.particles[0].position.copy()
        self.objective_function = objective_function

    def update_global_best(self):
        for particle in self.particles:
            current_fitness = self.objective_function(particle.position)
            global_best_fitness = self.objective_function(self.global_best)
            if current_fitness < global_best_fitness:
                self.global_best = particle.position.copy()

    def optimize(self, inertia, cognitive, social):
        while True:
            for particle in self.particles:
                particle.update_velocity(self.global_best, inertia, cognitive, social)
                particle.update_position()
                particle.update_best_position(self.objective_function)
            self.update_global_best()

def objective_function(x):
    return sum((xi ** 2 for xi in x))

def main():
    dimensions = 2
    num_particles = 30
    inertia = 0.7
    cognitive = 1.5
    social = 1.5
    swarm = Swarm(dimensions, num_particles, objective_function)
    swarm.optimize(inertia, cognitive, social)
main()