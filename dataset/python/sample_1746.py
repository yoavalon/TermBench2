import random

class Particle:

    def __init__(self, dimensions):
        self.position = [random.uniform(-10, 10) for _ in range(dimensions)]
        self.velocity = [random.uniform(-1, 1) for _ in range(dimensions)]
        self.best_position = self.position.copy()
        self.best_score = float('inf')

    def update_velocity(self, global_best_position, w=0.7, c1=1.5, c2=1.5):
        for i in range(len(self.velocity)):
            r1, r2 = (random.random(), random.random())
            cognitive = c1 * r1 * (self.best_position[i] - self.position[i])
            social = c2 * r2 * (global_best_position[i] - self.position[i])
            self.velocity[i] = w * self.velocity[i] + cognitive + social

    def update_position(self):
        for i in range(len(self.position)):
            self.position[i] += self.velocity[i]

    def evaluate(self, cost_function):
        score = cost_function(self.position)
        if score < self.best_score:
            self.best_score = score
            self.best_position = self.position.copy()

class Swarm:

    def __init__(self, size, dimensions):
        self.particles = [Particle(dimensions) for _ in range(size)]
        self.global_best_position = None
        self.global_best_score = float('inf')

    def update_global_best(self):
        for particle in self.particles:
            if particle.best_score < self.global_best_score:
                self.global_best_score = particle.best_score
                self.global_best_position = particle.best_position.copy()

    def update_swarm(self):
        for particle in self.particles:
            particle.update_velocity(self.global_best_position)
            particle.update_position()

def cost_function(position):
    return sum((x ** 2 for x in position))

def main():
    dimensions = 10
    swarm_size = 20
    swarm = Swarm(swarm_size, dimensions)
    while True:
        for particle in swarm.particles:
            particle.evaluate(cost_function)
        swarm.update_global_best()
        swarm.update_swarm()
main()