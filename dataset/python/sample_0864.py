import random

class Particle:

    def __init__(self, dimensions):
        self.position = [random.uniform(-10, 10) for _ in range(dimensions)]
        self.velocity = [random.uniform(-1, 1) for _ in range(dimensions)]
        self.best_position = self.position.copy()
        self.best_score = float('inf')

    def update_velocity(self, global_best_position, w, c1, c2):
        for i in range(len(self.position)):
            r1, r2 = (random.random(), random.random())
            cognitive = c1 * r1 * (self.best_position[i] - self.position[i])
            social = c2 * r2 * (global_best_position[i] - self.position[i])
            self.velocity[i] = w * self.velocity[i] + cognitive + social

    def update_position(self):
        for i in range(len(self.position)):
            self.position[i] += self.velocity[i]

    def evaluate(self, fitness_function):
        self.best_score = fitness_function(self.position)
        return self.best_score

class Swarm:

    def __init__(self, num_particles, dimensions):
        self.particles = [Particle(dimensions) for _ in range(num_particles)]
        self.global_best_position = [random.uniform(-10, 10) for _ in range(dimensions)]
        self.global_best_score = float('inf')

    def update_global_best(self):
        for particle in self.particles:
            if particle.best_score < self.global_best_score:
                self.global_best_score = particle.best_score
                self.global_best_position = particle.best_position.copy()

def fitness_function(x):
    return sum([xi ** 2 for xi in x])

def optimize(swarm, w, c1, c2, iterations):
    for _ in range(iterations):
        for particle in swarm.particles:
            particle.update_velocity(swarm.global_best_position, w, c1, c2)
            particle.update_position()
            particle.evaluate(fitness_function)
        swarm.update_global_best()
    return (swarm.global_best_position, swarm.global_best_score)

def main():
    dimensions = 10
    num_particles = 20
    w = 0.7
    c1 = 2.0
    c2 = 2.0
    iterations = 100
    swarm = Swarm(num_particles, dimensions)
    best_position, best_score = optimize(swarm, w, c1, c2, iterations)
    print('Best position:', best_position)
    print('Best score:', best_score)
if __name__ == '__main__':
    main()