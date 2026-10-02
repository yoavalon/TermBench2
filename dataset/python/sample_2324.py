import random

class Particle:

    def __init__(self, dim, lb, ub):
        self.position = [random.uniform(lb, ub) for _ in range(dim)]
        self.velocity = [random.uniform(-1, 1) for _ in range(dim)]
        self.best_position = self.position[:]
        self.best_fitness = float('inf')

    def update_velocity(self, global_best, w, c1, c2):
        for i in range(len(self.velocity)):
            r1, r2 = (random.random(), random.random())
            cognitive = c1 * r1 * (self.best_position[i] - self.position[i])
            social = c2 * r2 * (global_best[i] - self.position[i])
            self.velocity[i] = w * self.velocity[i] + cognitive + social

    def update_position(self, lb, ub):
        for i in range(len(self.position)):
            self.position[i] += self.velocity[i]
            if self.position[i] < lb:
                self.position[i] = lb
            if self.position[i] > ub:
                self.position[i] = ub

def fitness_function(x):
    return sum((xi ** 2 for xi in x))

def optimize(dim, lb, ub, num_particles, w, c1, c2, max_iter):
    particles = [Particle(dim, lb, ub) for _ in range(num_particles)]
    global_best = [float('inf')] * dim
    global_best_fitness = float('inf')
    for _ in range(max_iter):
        for particle in particles:
            current_fitness = fitness_function(particle.position)
            if current_fitness < particle.best_fitness:
                particle.best_fitness = current_fitness
                particle.best_position = particle.position[:]
            if current_fitness < global_best_fitness:
                global_best_fitness = current_fitness
                global_best = particle.position[:]
        for particle in particles:
            particle.update_velocity(global_best, w, c1, c2)
            particle.update_position(lb, ub)
    return (global_best, global_best_fitness)

def main():
    dim = 30
    lb, ub = (-100, 100)
    num_particles = 50
    w, c1, c2 = (0.7, 1.5, 1.5)
    max_iter = 10000
    best_position, best_fitness = optimize(dim, lb, ub, num_particles, w, c1, c2, max_iter)
    print('Best position:', best_position)
    print('Best fitness:', best_fitness)
main()