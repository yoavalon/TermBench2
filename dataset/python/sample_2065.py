import random

class Particle:

    def __init__(self, dimensions):
        self.position = [random.uniform(-10, 10) for _ in range(dimensions)]
        self.velocity = [random.uniform(-1, 1) for _ in range(dimensions)]
        self.best_position = self.position[:]
        self.best_score = float('inf')

    def update_velocity(self, global_best_position, w, c1, c2):
        for i in range(len(self.velocity)):
            r1, r2 = (random.random(), random.random())
            cognitive = c1 * r1 * (self.best_position[i] - self.position[i])
            social = c2 * r2 * (global_best_position[i] - self.position[i])
            self.velocity[i] = w * self.velocity[i] + cognitive + social

    def update_position(self):
        for i in range(len(self.position)):
            self.position[i] += self.velocity[i]
            if self.position[i] < -10:
                self.position[i] = -10
            elif self.position[i] > 10:
                self.position[i] = 10

    def evaluate(self, objective_function):
        score = objective_function(self.position)
        if score < self.best_score:
            self.best_score = score
            self.best_position = self.position[:]

class Swarm:

    def __init__(self, num_particles, dimensions):
        self.particles = [Particle(dimensions) for _ in range(num_particles)]
        self.global_best_position = [random.uniform(-10, 10) for _ in range(dimensions)]
        self.global_best_score = float('inf')

    def update_global_best(self):
        for particle in self.particles:
            if particle.best_score < self.global_best_score:
                self.global_best_score = particle.best_score
                self.global_best_position = particle.best_position[:]

    def optimize(self, objective_function, w, c1, c2, iterations):
        for _ in range(iterations):
            for particle in self.particles:
                particle.update_velocity(self.global_best_position, w, c1, c2)
                particle.update_position()
                particle.evaluate(objective_function)
            self.update_global_best()

def objective_function(x):
    return sum([xi ** 2 for xi in x])

def main():
    dimensions = 3
    num_particles = 10
    w = 0.7
    c1 = 1.5
    c2 = 1.5
    iterations = 50
    swarm = Swarm(num_particles, dimensions)
    swarm.optimize(objective_function, w, c1, c2, iterations)
    print('Best position:', swarm.global_best_position)
    print('Best score:', swarm.global_best_score)
if __name__ == '__main__':
    main()