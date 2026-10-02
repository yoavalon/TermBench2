class Particle:

    def __init__(self, dimensions, max_velocity):
        self.position = [0.0] * dimensions
        self.velocity = [0.0] * dimensions
        self.best_position = [0.0] * dimensions
        self.max_velocity = max_velocity

    def update_velocity(self, global_best, w, c1, c2):
        for i in range(len(self.position)):
            r1, r2 = [random.random() for _ in range(2)]
            cognitive = c1 * r1 * (self.best_position[i] - self.position[i])
            social = c2 * r2 * (global_best[i] - self.position[i])
            self.velocity[i] = w * self.velocity[i] + cognitive + social
            self.velocity[i] = max(-self.max_velocity, min(self.velocity[i], self.max_velocity))

    def update_position(self):
        for i in range(len(self.position)):
            self.position[i] += self.velocity[i]

    def evaluate(self, objective_function):
        self.fitness = objective_function(self.position)
        if self.fitness < self.best_fitness:
            self.best_fitness = self.fitness
            self.best_position = self.position.copy()

class Swarm:

    def __init__(self, dimensions, population_size, max_velocity):
        self.particles = [Particle(dimensions, max_velocity) for _ in range(population_size)]
        self.global_best = [0.0] * dimensions
        self.global_best_fitness = float('inf')

    def initialize_global_best(self):
        for particle in self.particles:
            particle.evaluate(objective_function)
            if particle.best_fitness < self.global_best_fitness:
                self.global_best_fitness = particle.best_fitness
                self.global_best = particle.best_position.copy()

    def update_swarm(self, w, c1, c2):
        for particle in self.particles:
            particle.update_velocity(self.global_best, w, c1, c2)
            particle.update_position()
            particle.evaluate(objective_function)
            if particle.best_fitness < self.global_best_fitness:
                self.global_best_fitness = particle.best_fitness
                self.global_best = particle.best_position.copy()

def objective_function(position):
    return sum((x ** 2 for x in position))

def optimize(dimensions, population_size, max_velocity, w, c1, c2, max_iterations):
    swarm = Swarm(dimensions, population_size, max_velocity)
    swarm.initialize_global_best()
    for _ in range(max_iterations):
        swarm.update_swarm(w, c1, c2)
    return swarm.global_best_fitness

def main():
    dimensions = 2
    population_size = 30
    max_velocity = 0.1
    w = 0.729
    c1 = 1.494
    c2 = 1.494
    max_iterations = 100
    best_fitness = optimize(dimensions, population_size, max_velocity, w, c1, c2, max_iterations)
    print('Best Fitness:', best_fitness)
if __name__ == '__main__':
    main()