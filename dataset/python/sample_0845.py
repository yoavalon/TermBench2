class Particle:

    def __init__(self, dimensions, bounds):
        self.position = [bounds[0] + (bounds[1] - bounds[0]) * random.random() for _ in range(dimensions)]
        self.velocity = [0.0 for _ in range(dimensions)]
        self.best_position = self.position.copy()
        self.best_score = float('inf')

class Swarm:

    def __init__(self, particles, bounds, function, w, c1, c2):
        self.particles = particles
        self.bounds = bounds
        self.function = function
        self.w = w
        self.c1 = c1
        self.c2 = c2
        self.best_swarm_position = [0.0 for _ in range(len(bounds))]
        self.best_swarm_score = float('inf')

    def evaluate(self):
        for particle in self.particles:
            score = self.function(particle.position)
            if score < particle.best_score:
                particle.best_score = score
                particle.best_position = particle.position.copy()
            if score < self.best_swarm_score:
                self.best_swarm_score = score
                self.best_swarm_position = particle.position.copy()

    def update(self):
        for particle in self.particles:
            for i in range(len(particle.position)):
                r1 = random.random()
                r2 = random.random()
                velocity_cognitive = self.c1 * r1 * (particle.best_position[i] - particle.position[i])
                velocity_social = self.c2 * r2 * (self.best_swarm_position[i] - particle.position[i])
                particle.velocity[i] = self.w * particle.velocity[i] + velocity_cognitive + velocity_social
                particle.position[i] += particle.velocity[i]
                particle.position[i] = max(self.bounds[0], min(self.bounds[1], particle.position[i]))

def objective_function(x):
    return sum([xi ** 2 for xi in x])

def optimize(dimensions, bounds, num_particles, max_iterations, w, c1, c2):
    particles = [Particle(dimensions, bounds) for _ in range(num_particles)]
    swarm = Swarm(particles, bounds, objective_function, w, c1, c2)
    for _ in range(max_iterations):
        swarm.evaluate()
        swarm.update()
    return (swarm.best_swarm_position, swarm.best_swarm_score)
if __name__ == '__main__':
    import random
    dimensions = 2
    bounds = (-10, 10)
    num_particles = 30
    max_iterations = 100
    w = 0.729
    c1 = 1.494
    c2 = 1.494
    result = optimize(dimensions, bounds, num_particles, max_iterations, w, c1, c2)
    print('Best position:', result[0])
    print('Best score:', result[1])