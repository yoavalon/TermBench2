import random

class Swarm:

    def __init__(self, size, dimensions):
        self.size = size
        self.dimensions = dimensions
        self.particles = [Particle(dimensions) for _ in range(size)]
        self.best_position = None
        self.best_value = float('inf')

    def update_best(self):
        for particle in self.particles:
            if particle.value < self.best_value:
                self.best_value = particle.value
                self.best_position = particle.position.copy()

    def optimize(self, iterations):
        for _ in range(iterations):
            for particle in self.particles:
                particle.update(self.best_position)
            self.update_best()

class Particle:

    def __init__(self, dimensions):
        self.position = [random.uniform(-10, 10) for _ in range(dimensions)]
        self.velocity = [random.uniform(-1, 1) for _ in range(dimensions)]
        self.best_position = self.position.copy()
        self.best_value = self.calculate_value()

    def calculate_value(self):
        return sum((x ** 2 for x in self.position))

    def update(self, global_best):
        w = 0.7
        c1 = 1.5
        c2 = 1.5
        for i in range(len(self.position)):
            r1 = random.random()
            r2 = random.random()
            self.velocity[i] = w * self.velocity[i] + c1 * r1 * (self.best_position[i] - self.position[i]) + c2 * r2 * (global_best[i] - self.position[i])
            self.position[i] += self.velocity[i]
        self.value = self.calculate_value()
        if self.value < self.best_value:
            self.best_value = self.value
            self.best_position = self.position.copy()

def main():
    dimensions = 2
    swarm_size = 30
    iterations = 100
    swarm = Swarm(swarm_size, dimensions)
    swarm.optimize(iterations)
    print('Best position:', swarm.best_position)
    print('Best value:', swarm.best_value)
if __name__ == '__main__':
    main()