import random

class Swarm:

    def __init__(self, size, dimensions, search_space):
        self.size = size
        self.dimensions = dimensions
        self.search_space = search_space
        self.particles = [Particle(dimensions, search_space) for _ in range(size)]

    def update(self):
        for particle in self.particles:
            particle.update_velocity()
            particle.update_position()

class Particle:

    def __init__(self, dimensions, search_space):
        self.dimensions = dimensions
        self.search_space = search_space
        self.position = [random.uniform(search_space[0], search_space[1]) for _ in range(dimensions)]
        self.velocity = [random.uniform(-1, 1) for _ in range(dimensions)]
        self.best_position = self.position.copy()
        self.best_fitness = float('inf')

    def update_velocity(self):
        w = 0.7
        c1 = 1.5
        c2 = 1.5
        for i in range(self.dimensions):
            r1, r2 = (random.random(), random.random())
            cognitive = c1 * r1 * (self.best_position[i] - self.position[i])
            social = c2 * r2 * (self.best_position[i] - self.position[i])
            self.velocity[i] = w * self.velocity[i] + cognitive + social

    def update_position(self):
        for i in range(self.dimensions):
            self.position[i] += self.velocity[i]
            self.position[i] = max(self.search_space[0], min(self.search_space[1], self.position[i]))

def fitness_function(position):
    return sum((x ** 2 for x in position))

def optimize(swarm, max_iterations):
    for iteration in range(max_iterations):
        for particle in swarm.particles:
            current_fitness = fitness_function(particle.position)
            if current_fitness < particle.best_fitness:
                particle.best_fitness = current_fitness
                particle.best_position = particle.position.copy()
        swarm.update()

def main():
    size = 30
    dimensions = 2
    search_space = (-10, 10)
    max_iterations = 100
    swarm = Swarm(size, dimensions, search_space)
    optimize(swarm, max_iterations)
if __name__ == '__main__':
    main()