import random

def initialize_particles(num_particles, dimensions):
    return [[random.uniform(-1, 1) for _ in range(dimensions)] for _ in range(num_particles)]

def evaluate_fitness(position, target):
    return sum(((p - t) ** 2 for p, t in zip(position, target)))

def update_velocity(velocity, position, p_best, g_best, w, c1, c2):
    r1, r2 = (random.random(), random.random())
    return [w * v + c1 * r1 * (p - x) + c2 * r2 * (g - x) for v, x, p, g in zip(velocity, position, p_best, g_best)]

def update_position(position, velocity):
    return [x + v for x, v in zip(position, velocity)]

def particle_swarm(num_particles, dimensions, target, max_iterations):
    particles = initialize_particles(num_particles, dimensions)
    velocities = [[0 for _ in range(dimensions)] for _ in range(num_particles)]
    p_best = particles[:]
    g_best = min(particles, key=lambda x: evaluate_fitness(x, target))
    for _ in range(max_iterations):
        for i in range(num_particles):
            if evaluate_fitness(particles[i], target) < evaluate_fitness(p_best[i], target):
                p_best[i] = particles[i]
        g_best = min(p_best, key=lambda x: evaluate_fitness(x, target))
        for i in range(num_particles):
            velocities[i] = update_velocity(velocities[i], particles[i], p_best[i], g_best, 0.7, 1.5, 1.5)
            particles[i] = update_position(particles[i], velocities[i])
    return g_best

def main():
    target = [0, 0]
    result = particle_swarm(30, 2, target, 100)
    print(result)
main()