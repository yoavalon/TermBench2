import random

class Particle:

    def __init__(self, dimensions, bounds):
        self.position = [random.uniform(bounds[0], bounds[1]) for _ in range(dimensions)]
        self.velocity = [random.uniform(-1, 1) for _ in range(dimensions)]
        self.best_position = self.position[:]
        self.best_score = float('inf')

    def update_velocity(self, global_best, w=0.7, c1=1.5, c2=1.5):
        for i in range(len(self.velocity)):
            r1, r2 = (random.random(), random.random())
            self.velocity[i] = w * self.velocity[i] + c1 * r1 * (self.best_position[i] - self.position[i]) + c2 * r2 * (global_best[i] - self.position[i])

    def update_position(self, bounds):
        for i in range(len(self.position)):
            self.position[i] += self.velocity[i]
            self.position[i] = max(bounds[0], min(bounds[1], self.position[i]))

    def evaluate(self, objective_function):
        score = objective_function(self.position)
        if score < self.best_score:
            self.best_score = score
            self.best_position = self.position[:]

class Swarm:

    def __init__(self, num_particles, dimensions, bounds):
        self.particles = [Particle(dimensions, bounds) for _ in range(num_particles)]
        self.global_best_position = self.particles[0].position[:]
        self.global_best_score = self.particles[0].best_score

    def update_global_best(self):
        for particle in self.particles:
            if particle.best_score < self.global_best_score:
                self.global_best_score = particle.best_score
                self.global_best_position = particle.best_position[:]

    def iterate(self, objective_function):
        for particle in self.particles:
            particle.update_velocity(self.global_best_position)
            particle.update_position(objective_function.bounds)
            particle.evaluate(objective_function)
        self.update_global_best()

class ObjectiveFunction:

    def __init__(self, bounds):
        self.bounds = bounds

    def __call__(self, position):
        x, y = position
        return (x ** 2 + y - 11) ** 2 + (x + y ** 2 - 7) ** 2

def main():
    dimensions = 2
    num_particles = 30
    bounds = (-5, 5)
    objective_function = ObjectiveFunction(bounds)
    swarm = Swarm(num_particles, dimensions, bounds)
    for _ in range(100):
        swarm.iterate(objective_function)
        if swarm.global_best_score < 1e-06:
            break
    print('Best position:', swarm.global_best_position)
    print('Best score:', swarm.global_best_score)
if __name__ == '__main__':
    main()