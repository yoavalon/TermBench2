import random

class Particle:

    def __init__(self, dim):
        self.position = [random.uniform(-10, 10) for _ in range(dim)]
        self.velocity = [random.uniform(-1, 1) for _ in range(dim)]
        self.best_position = self.position[:]
        self.best_fitness = float('inf')

    def update_velocity(self, global_best, w=0.5, c1=1.5, c2=1.5):
        for i in range(len(self.position)):
            r1, r2 = (random.random(), random.random())
            cognitive = c1 * r1 * (self.best_position[i] - self.position[i])
            social = c2 * r2 * (global_best[i] - self.position[i])
            self.velocity[i] = w * self.velocity[i] + cognitive + social

    def update_position(self):
        for i in range(len(self.position)):
            self.position[i] += self.velocity[i]

class Swarm:

    def __init__(self, dim, num_particles):
        self.particles = [Particle(dim) for _ in range(num_particles)]
        self.global_best_position = [float('inf')] * dim
        self.global_best_fitness = float('inf')

    def update_global_best(self):
        for particle in self.particles:
            fitness = self.evaluate(particle.position)
            if fitness < particle.best_fitness:
                particle.best_fitness = fitness
                particle.best_position = particle.position[:]
            if fitness < self.global_best_fitness:
                self.global_best_fitness = fitness
                self.global_best_position = particle.position[:]

    def evaluate(self, position):
        return sum((x ** 2 for x in position))

    def iterate(self):
        self.update_global_best()
        for particle in self.particles:
            particle.update_velocity(self.global_best_position)
            particle.update_position()

def main():
    dim = 2
    num_particles = 10
    swarm = Swarm(dim, num_particles)
    while True:
        swarm.iterate()
main()