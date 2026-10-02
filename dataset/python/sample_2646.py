import random

class Swarm:

    def __init__(self, size, dimensions, search_space):
        self.size = size
        self.dimensions = dimensions
        self.search_space = search_space
        self.particles = [Particle(dimensions, search_space) for _ in range(size)]
        self.best_position = random.choice(self.particles).position
        self.best_score = float('inf')

    def update_best_position(self):
        for particle in self.particles:
            if particle.score < self.best_score:
                self.best_score = particle.score
                self.best_position = particle.position

    def iterate(self):
        for particle in self.particles:
            particle.update_velocity(self.best_position)
            particle.move()
            particle.evaluate()

    def run(self, iterations):
        for _ in range(iterations):
            self.iterate()
            self.update_best_position()

class Particle:

    def __init__(self, dimensions, search_space):
        self.position = [random.uniform(*search_space) for _ in range(dimensions)]
        self.velocity = [0.0 for _ in range(dimensions)]
        self.best_position = self.position[:]
        self.best_score = float('inf')

    def update_velocity(self, global_best):
        inertia = 0.5
        cognitive_factor = 1.5
        social_factor = 1.5
        for i in range(len(self.position)):
            r1, r2 = (random.random(), random.random())
            cognitive = cognitive_factor * r1 * (self.best_position[i] - self.position[i])
            social = social_factor * r2 * (global_best[i] - self.position[i])
            self.velocity[i] = inertia * self.velocity[i] + cognitive + social

    def move(self):
        for i in range(len(self.position)):
            self.position[i] += self.velocity[i]

    def evaluate(self):
        self.score = self.objective_function()
        if self.score < self.best_score:
            self.best_score = self.score
            self.best_position = self.position[:]

    def objective_function(self):
        return sum((x ** 2 for x in self.position))

def main():
    swarm_size = 30
    dimensions = 2
    search_space = (-10, 10)
    iterations = 100
    swarm = Swarm(swarm_size, dimensions, search_space)
    swarm.run(iterations)
    print('Best position:', swarm.best_position)
    print('Best score:', swarm.best_score)
if __name__ == '__main__':
    main()