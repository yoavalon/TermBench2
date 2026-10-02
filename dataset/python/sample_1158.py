class Particle:

    def __init__(self, position, velocity, best_position):
        self.position = position
        self.velocity = velocity
        self.best_position = best_position

    def update_velocity(self, global_best, w, c1, c2):
        r1, r2 = (0.5, 0.3)
        new_velocity = w * self.velocity + c1 * r1 * (self.best_position - self.position) + c2 * r2 * (global_best - self.position)
        self.velocity = new_velocity

    def update_position(self):
        self.position += self.velocity
        if self.position < self.best_position:
            self.best_position = self.position

def update_global_best(particles):
    best = particles[0].best_position
    for particle in particles:
        if particle.best_position < best:
            best = particle.best_position
    return best

def optimize(particles, global_best, w, c1, c2, iterations):
    if iterations == 0:
        return global_best
    for particle in particles:
        particle.update_velocity(global_best, w, c1, c2)
        particle.update_position()
    new_global_best = update_global_best(particles)
    return optimize(particles, new_global_best, w, c1, c2, iterations - 1)

def main():
    num_particles = 10
    initial_positions = [0.0] * num_particles
    initial_velocities = [0.1] * num_particles
    best_positions = [0.0] * num_particles
    particles = [Particle(pos, vel, best) for pos, vel, best in zip(initial_positions, initial_velocities, best_positions)]
    global_best = update_global_best(particles)
    w, c1, c2 = (0.7, 1.5, 1.5)
    iterations = float('inf')
    optimize(particles, global_best, w, c1, c2, iterations)
main()