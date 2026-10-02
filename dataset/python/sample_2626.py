import random

class Particle:

    def __init__(self, dimensions, position=None):
        self.position = position if position is not None else [random.uniform(-1, 1) for _ in range(dimensions)]
        self.velocity = [random.uniform(-1, 1) for _ in range(dimensions)]
        self.best_position = self.position[:]
        self.best_score = float('inf')

    def update_velocity(self, global_best, w=0.7, c1=1.5, c2=1.5):
        for i in range(len(self.position)):
            r1, r2 = (random.random(), random.random())
            cognitive = c1 * r1 * (self.best_position[i] - self.position[i])
            social = c2 * r2 * (global_best[i] - self.position[i])
            self.velocity[i] = w * self.velocity[i] + cognitive + social

    def update_position(self, bounds):
        for i in range(len(self.position)):
            self.position[i] += self.velocity[i]
            if bounds:
                self.position[i] = max(bounds[0], min(bounds[1], self.position[i]))

    def evaluate(self, function):
        self.current_score = function(self.position)
        if self.current_score < self.best_score:
            self.best_score = self.current_score
            self.best_position = self.position[:]

class Swarm:

    def __init__(self, dimensions, num_particles, bounds=None):
        self.particles = [Particle(dimensions) for _ in range(num_particles)]
        self.global_best = None
        self.global_best_score = float('inf')
        self.bounds = bounds

    def update_global_best(self):
        for particle in self.particles:
            if particle.best_score < self.global_best_score:
                self.global_best_score = particle.best_score
                self.global_best = particle.best_position[:]

    def optimize(self, function, iterations):
        for _ in range(iterations):
            self.update_global_best()
            for particle in self.particles:
                particle.update_velocity(self.global_best)
                particle.update_position(self.bounds)
                particle.evaluate(function)

def objective_function(x):
    return sum((xi ** 2 for xi in x))

def main():
    dimensions = 2
    num_particles = 30
    bounds = (-10, 10)
    iterations = 100
    swarm = Swarm(dimensions, num_particles, bounds)
    swarm.optimize(objective_function, iterations)
    print('Global Best Position:', swarm.global_best)
    print('Global Best Score:', swarm.global_best_score)
if __name__ == '__main__':
    main()