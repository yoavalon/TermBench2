class Particle:

    def __init__(self, dim):
        self.position = [0.0] * dim
        self.velocity = [0.0] * dim
        self.pbest = [0.0] * dim
        self.pbest_value = float('inf')

    def update_velocity(self, gbest, w=0.7, c1=1.5, c2=1.5):
        for i in range(len(self.position)):
            r1, r2 = (0.5, 0.5)
            self.velocity[i] = w * self.velocity[i] + c1 * r1 * (self.pbest[i] - self.position[i]) + c2 * r2 * (gbest[i] - self.position[i])

    def update_position(self, bounds):
        for i in range(len(self.position)):
            self.position[i] += self.velocity[i]
            self.position[i] = max(bounds[i][0], min(bounds[i][1], self.position[i]))

    def update_pbest(self, value):
        if value < self.pbest_value:
            self.pbest = self.position[:]
            self.pbest_value = value

class Swarm:

    def __init__(self, num_particles, dim, bounds):
        self.particles = [Particle(dim) for _ in range(num_particles)]
        self.gbest = [0.0] * dim
        self.gbest_value = float('inf')
        self.bounds = bounds

    def update_gbest(self):
        for particle in self.particles:
            if particle.pbest_value < self.gbest_value:
                self.gbest = particle.pbest[:]
                self.gbest_value = particle.pbest_value

    def iterate(self):
        for particle in self.particles:
            particle.update_velocity(self.gbest)
            particle.update_position(self.bounds)
            particle.update_pbest(objective_function(particle.position))

def objective_function(x):
    return sum((xi ** 2 for xi in x))

def optimize(num_particles, dim, max_iterations, bounds):
    swarm = Swarm(num_particles, dim, bounds)
    for _ in range(max_iterations):
        swarm.iterate()
        swarm.update_gbest()
    return (swarm.gbest, swarm.gbest_value)

def main():
    num_particles = 30
    dim = 2
    max_iterations = 100
    bounds = [(-10, 10)] * dim
    best_position, best_value = optimize(num_particles, dim, max_iterations, bounds)
    print('Best position:', best_position)
    print('Best value:', best_value)
if __name__ == '__main__':
    main()