import random

def update_velocity(p, g, v, w, c1, c2):
    r1, r2 = (random.random(), random.random())
    return w * v + c1 * r1 * (p - g) + c2 * r2 * (p - p)

def update_position(p, v):
    return p + v

def optimize(particles, velocities, best_positions, global_best, w, c1, c2):
    new_particles = []
    new_velocities = []
    new_best_positions = []
    for i in range(len(particles)):
        v = update_velocity(particles[i], global_best, velocities[i], w, c1, c2)
        p = update_position(particles[i], v)
        new_particles.append(p)
        new_velocities.append(v)
        if p < best_positions[i]:
            new_best_positions.append(p)
        else:
            new_best_positions.append(best_positions[i])
    return (new_particles, new_velocities, new_best_positions)

def swarm():
    particles = [random.random() for _ in range(10)]
    velocities = [random.random() for _ in range(10)]
    best_positions = particles[:]
    global_best = min(particles)
    w, c1, c2 = (0.7, 1.5, 1.5)
    while True:
        particles, velocities, best_positions = optimize(particles, velocities, best_positions, global_best, w, c1, c2)
        global_best = min(best_positions)
swarm()