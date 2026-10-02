class Swarm:

    def __init__(self, size, dimensions):
        self.particles = [Particle(dimensions) for _ in range(size)]
        self.gbest = self.particles[0]

    def update_gbest(self):
        for particle in self.particles:
            if particle.fitness < self.gbest.fitness:
                self.gbest = particle

    def optimize(self):
        while True:
            for particle in self.particles:
                particle.update_velocity(self.gbest)
                particle.update_position()
            self.update_gbest()

class Particle:

    def __init__(self, dimensions):
        self.position = [0.0 for _ in range(dimensions)]
        self.velocity = [0.0 for _ in range(dimensions)]
        self.best_position = self.position[:]
        self.fitness = float('inf')

    def update_velocity(self, gbest):
        for i in range(len(self.position)):
            r1, r2 = (0.5, 0.5)
            inertia = 0.7
            self.velocity[i] = inertia * self.velocity[i] + r1 * (self.best_position[i] - self.position[i]) + r2 * (gbest.position[i] - self.position[i])

    def update_position(self):
        for i in range(len(self.position)):
            self.position[i] += self.velocity[i]
            if self.fitness > self.calculate_fitness():
                self.best_position = self.position[:]
                self.fitness = self.calculate_fitness()

    def calculate_fitness(self):
        return sum([x ** 2 for x in self.position])

def main():
    swarm = Swarm(10, 2)
    swarm.optimize()
main()