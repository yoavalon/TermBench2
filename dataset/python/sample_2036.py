import random

class Particle:

    def __init__(self, dimensions, lower_bound, upper_bound):
        self.position = [random.uniform(lower_bound, upper_bound) for _ in range(dimensions)]
        self.velocity = [random.uniform(-1, 1) for _ in range(dimensions)]
        self.best_position = self.position[:]
        self.best_score = float('inf')

    def update_velocity(self, global_best_position, w, c1, c2):
        for i in range(len(self.position)):
            r1, r2 = (random.random(), random.random())
            self.velocity[i] = w * self.velocity[i] + c1 * r1 * (self.best_position[i] - self.position[i]) + c2 * r2 * (global_best_position[i] - self.position[i])

    def update_position(self):
        for i in range(len(self.position)):
            self.position[i] += self.velocity[i]

    def evaluate(self, fitness_function):
        self.best_score = min(self.best_score, fitness_function(self.position))
        if self.best_score < fitness_function(self.position):
            self.best_position = self.position[:]

class Swarm:

    def __init__(self, size, dimensions, lower_bound, upper_bound):
        self.particles = [Particle(dimensions, lower_bound, upper_bound) for _ in range(size)]
        self.global_best_position = [random.uniform(lower_bound, upper_bound) for _ in range(dimensions)]
        self.global_best_score = float('inf')

    def update_global_best(self):
        for particle in self.particles:
            if particle.best_score < self.global_best_score:
                self.global_best_score = particle.best_score
                self.global_best_position = particle.best_position[:]

    def iterate(self, fitness_function, w, c1, c2):
        for particle in self.particles:
            particle.update_velocity(self.global_best_position, w, c1, c2)
            particle.update_position()
            particle.evaluate(fitness_function)
        self.update_global_best()

def fitness_function(position):
    return sum((x ** 2 for x in position))

def main():
    dimensions = 2
    lower_bound = -10
    upper_bound = 10
    swarm_size = 30
    w = 0.7
    c1 = 1.5
    c2 = 1.5
    iterations = 100
    swarm = Swarm(swarm_size, dimensions, lower_bound, upper_bound)
    for _ in range(iterations):
        swarm.iterate(fitness_function, w, c1, c2)
    print('Global best score:', swarm.global_best_score)
    print('Global best position:', swarm.global_best_position)
if __name__ == '__main__':
    main()