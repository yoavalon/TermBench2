import random

class Particle:

    def __init__(self, dim, bounds):
        self.position = [random.uniform(b[0], b[1]) for b in bounds]
        self.velocity = [random.uniform(-1, 1) for _ in range(dim)]
        self.best_pos = self.position[:]
        self.best_score = float('inf')

    def update_velocity(self, global_best, w=0.7, c1=1.5, c2=1.5):
        for i in range(len(self.position)):
            r1, r2 = (random.random(), random.random())
            cognitive = c1 * r1 * (self.best_pos[i] - self.position[i])
            social = c2 * r2 * (global_best[i] - self.position[i])
            self.velocity[i] = w * self.velocity[i] + cognitive + social

    def update_position(self, bounds):
        for i in range(len(self.position)):
            self.position[i] += self.velocity[i]
            self.position[i] = max(bounds[i][0], min(self.position[i], bounds[i][1]))

class Swarm:

    def __init__(self, dim, num_particles, bounds):
        self.particles = [Particle(dim, bounds) for _ in range(num_particles)]
        self.global_best = [float('inf') for _ in range(dim)]
        self.global_best_score = float('inf')

    def update_global_best(self):
        for particle in self.particles:
            score = self.evaluate(particle.position)
            if score < self.global_best_score:
                self.global_best = particle.position[:]
                self.global_best_score = score
                particle.best_score = score
                particle.best_pos = particle.position[:]

    def evaluate(self, position):
        return sum((x ** 2 for x in position))

    def run(self, iterations):
        for _ in range(iterations):
            for particle in self.particles:
                particle.update_velocity(self.global_best)
                particle.update_position(self.bound)
            self.update_global_best()

def main():
    dim = 3
    num_particles = 20
    bounds = [(-10, 10) for _ in range(dim)]
    swarm = Swarm(dim, num_particles, bounds)
    swarm.run(100)
    print('Global Best Position:', swarm.global_best)
    print('Global Best Score:', swarm.global_best_score)
if __name__ == '__main__':
    main()