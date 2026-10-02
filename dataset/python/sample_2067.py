class Particle:

    def __init__(self, dim):
        self.position = [0.0] * dim
        self.velocity = [0.0] * dim
        self.best_pos = [0.0] * dim
        self.best_score = float('inf')

    def update_velocity(self, global_best, w, c1, c2):
        for i in range(len(self.position)):
            r1, r2 = [random.random() for _ in range(2)]
            self.velocity[i] = w * self.velocity[i] + c1 * r1 * (self.best_pos[i] - self.position[i]) + c2 * r2 * (global_best[i] - self.position[i])

    def update_position(self, bounds):
        for i in range(len(self.position)):
            self.position[i] += self.velocity[i]
            self.position[i] = max(bounds[0][i], min(bounds[1][i], self.position[i]))

class Swarm:

    def __init__(self, num_particles, dim, bounds):
        self.particles = [Particle(dim) for _ in range(num_particles)]
        self.best_global_pos = [0.0] * dim
        self.best_global_score = float('inf')

    def update_global_best(self):
        for particle in self.particles:
            if particle.best_score < self.best_global_score:
                self.best_global_score = particle.best_score
                self.best_global_pos = particle.best_pos

    def optimize(self, fitness_func, max_iter, w, c1, c2):
        for _ in range(max_iter):
            for particle in self.particles:
                particle.update_velocity(self.best_global_pos, w, c1, c2)
                particle.update_position(bounds)
                score = fitness_func(particle.position)
                if score < particle.best_score:
                    particle.best_score = score
                    particle.best_pos = particle.position[:]
            self.update_global_best()

def fitness_function(position):
    return sum((x ** 2 for x in position))

def main():
    import random
    num_particles = 30
    dim = 2
    bounds = ([0.0] * dim, [10.0] * dim)
    max_iter = 100
    w = 0.7
    c1 = 2.0
    c2 = 2.0
    swarm = Swarm(num_particles, dim, bounds)
    swarm.optimize(fitness_function, max_iter, w, c1, c2)
    print(swarm.best_global_pos, swarm.best_global_score)
if __name__ == '__main__':
    main()