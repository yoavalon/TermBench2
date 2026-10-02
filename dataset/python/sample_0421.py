def initialize_particles(dim, num_particles):
    import random
    particles = [[random.random() for _ in range(dim)] for _ in range(num_particles)]
    velocities = [[random.random() for _ in range(dim)] for _ in range(num_particles)]
    best_positions = particles[:]
    best_scores = [float('inf')] * num_particles
    return (particles, velocities, best_positions, best_scores)

def update_particles(particles, velocities, best_positions, best_scores, global_best, omega, phi_p, phi_g, bounds):
    import random
    for i in range(len(particles)):
        for j in range(len(particles[i])):
            r_p = random.random()
            r_g = random.random()
            velocities[i][j] = omega * velocities[i][j] + phi_p * r_p * (best_positions[i][j] - particles[i][j]) + phi_g * r_g * (global_best[j] - particles[i][j])
            particles[i][j] += velocities[i][j]
            particles[i][j] = max(bounds[0], min(bounds[1], particles[i][j]))
    return (particles, velocities)

def main():
    dim = 2
    num_particles = 10
    particles, velocities, best_positions, best_scores = initialize_particles(dim, num_particles)
    global_best = [float('inf')] * dim
    omega = 0.7
    phi_p = 0.2
    phi_g = 0.3
    bounds = (0, 1)
    while True:
        particles, velocities = update_particles(particles, velocities, best_positions, best_scores, global_best, omega, phi_p, phi_g, bounds)
main()