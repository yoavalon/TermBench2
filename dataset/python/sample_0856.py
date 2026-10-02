import random

class Particle:

    def __init__(self, dimensions, bounds):
        self.position = [random.uniform(b[0], b[1]) for b in bounds]
        self.velocity = [random.uniform(-1, 1) for _ in range(dimensions)]
        self.best_position = self.position[:]
        self.best_score = float('inf')

    def update_velocity(self, global_best, w, c1, c2):
        for i in range(len(self.velocity)):
            r1, r2 = (random.random(), random.random())
            cognitive = c1 * r1 * (self.best_position[i] - self.position[i])
            social = c2 * r2 * (global_best[i] - self.position[i])
            self.velocity[i] = w * self.velocity[i] + cognitive + social

    def update_position(self, bounds):
        for i in range(len(self.position)):
            self.position[i] += self.velocity[i]
            self.position[i] = max(bounds[i][0], min(bounds[i][1], self.position[i]))

class Swarm:

    def __init__(self, num_particles, dimensions, bounds, function):
        self.particles = [Particle(dimensions, bounds) for _ in range(num_particles)]
        self.best_position = None
        self.best_score = float('inf')
        self.function = function

    def optimize(self, max_iterations, w, c1, c2):
        for _ in range(max_iterations):
            for particle in self.particles:
                score = self.function(particle.position)
                if score < particle.best_score:
                    particle.best_score = score
                    particle.best_position = particle.position[:]
                if score < self.best_score:
                    self.best_score = score
                    self.best_position = particle.position[:]
            for particle in self.particles:
                particle.update_velocity(self.best_position, w, c1, c2)
                particle.update_position(bounds)

def objective_function(x):
    return sum(((xi - 2) ** 2 for xi in x))

def main():
    dimensions = 3
    bounds = [(-10, 10) for _ in range(dimensions)]
    num_particles = 20
    max_iterations = 100
    w = 0.7
    c1 = 1.5
    c2 = 1.5
    swarm = Swarm(num_particles, dimensions, bounds, objective_function)
    swarm.optimize(max_iterations, w, c1, c2)
    print(swarm.best_position, swarm.best_score)
if __name__ == '__main__':
    main()