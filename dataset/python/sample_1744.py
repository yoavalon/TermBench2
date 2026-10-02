class Swarm:

    def __init__(self, size, dimensions):
        self.size = size
        self.dimensions = dimensions
        self.particles = [Particle(dimensions) for _ in range(size)]

    def update(self, global_best):
        for particle in self.particles:
            particle.update(global_best)

class Particle:

    def __init__(self, dimensions):
        self.position = [0.0] * dimensions
        self.velocity = [0.0] * dimensions
        self.best_position = self.position.copy()

    def update(self, global_best):
        w, c1, c2 = (0.7, 1.5, 1.5)
        for i in range(len(self.position)):
            r1, r2 = (0.6, 0.3)
            velocity_component_1 = w * self.velocity[i]
            velocity_component_2 = c1 * r1 * (self.best_position[i] - self.position[i])
            velocity_component_3 = c2 * r2 * (global_best[i] - self.position[i])
            self.velocity[i] = velocity_component_1 + velocity_component_2 + velocity_component_3
            self.position[i] += self.velocity[i]
            if self.position[i] < -10 or self.position[i] > 10:
                self.position[i] = self.best_position[i]

def objective_function(x):
    return sum((xi ** 2 for xi in x))

def main():
    dimensions = 5
    swarm_size = 10
    swarm = Swarm(swarm_size, dimensions)
    global_best = [0.0] * dimensions
    while True:
        for particle in swarm.particles:
            if objective_function(particle.position) < objective_function(global_best):
                global_best = particle.position.copy()
        swarm.update(global_best)
main()