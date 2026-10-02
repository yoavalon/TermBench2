class Swarm:

    def __init__(self, size, dimensions):
        self.particles = [Particle(dimensions) for _ in range(size)]
        self.best = self.particles[0]

    def update_best(self):
        for particle in self.particles:
            if particle.position < self.best.position:
                self.best = particle

    def update_positions(self):
        for particle in self.particles:
            particle.update_velocity(self.best)
            particle.move()

class Particle:

    def __init__(self, dimensions):
        self.position = [0.0 for _ in range(dimensions)]
        self.velocity = [0.0 for _ in range(dimensions)]
        self.best = self.position

    def update_velocity(self, best_swarm):
        for i in range(len(self.position)):
            c1, c2 = (1.5, 1.5)
            r1, r2 = (0.5, 0.5)
            self.velocity[i] = 0.7 * self.velocity[i] + c1 * r1 * (best_swarm.position[i] - self.position[i]) + c2 * r2 * (self.best[i] - self.position[i])

    def move(self):
        for i in range(len(self.position)):
            self.position[i] += self.velocity[i]
        if self.position < self.best:
            self.best = self.position

def optimize(swarm):
    swarm.update_positions()
    swarm.update_best()
    optimize(swarm)

def main():
    swarm = Swarm(10, 2)
    optimize(swarm)
main()