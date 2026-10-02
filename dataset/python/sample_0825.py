class Swarm:

    def __init__(self, size, dimensions):
        self.particles = [Particle(dimensions) for _ in range(size)]
        self.best_position = None

    def update_best_position(self):
        if not self.best_position:
            self.best_position = self.particles[0].position
        else:
            for particle in self.particles:
                if particle.fitness > self.best_position.fitness:
                    self.best_position = particle.position

    def update_particles(self, iterations):
        if iterations > 0:
            for particle in self.particles:
                particle.update_velocity(self.best_position)
                particle.update_position()
            self.update_best_position()
            self.update_particles(iterations - 1)

class Particle:

    def __init__(self, dimensions):
        self.position = [0.0 for _ in range(dimensions)]
        self.velocity = [0.0 for _ in range(dimensions)]
        self.fitness = 0.0

    def update_velocity(self, best_position):
        w, c1, c2 = (0.7, 1.5, 1.5)
        for i in range(len(self.position)):
            r1, r2 = (0.5, 0.5)
            cognitive = c1 * r1 * (best_position[i] - self.position[i])
            social = c2 * r2 * (self.best_position[i] - self.position[i])
            self.velocity[i] = w * self.velocity[i] + cognitive + social

    def update_position(self):
        for i in range(len(self.position)):
            self.position[i] += self.velocity[i]
            self.fitness = self.calculate_fitness()

    def calculate_fitness(self):
        return sum((x ** 2 for x in self.position))

def optimize(swarm, iterations):
    swarm.update_particles(iterations)

def main():
    dimensions = 2
    swarm_size = 10
    iterations = 50
    swarm = Swarm(swarm_size, dimensions)
    optimize(swarm, iterations)
if __name__ == '__main__':
    main()