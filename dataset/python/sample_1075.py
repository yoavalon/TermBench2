import random

def update_velocity(p, g, l, w, c1, c2):
    r1, r2 = (random.random(), random.random())
    return w * l + c1 * r1 * (p - l) + c2 * r2 * (g - l)

def update_position(l, v):
    return l + v

def swarm_search(f, bounds, n_particles, w, c1, c2):
    particles = [[random.uniform(b[0], b[1]) for b in bounds] for _ in range(n_particles)]
    velocities = [[0 for _ in bounds] for _ in range(n_particles)]
    pbest = particles.copy()
    gbest = min(particles, key=f)
    while True:
        for i in range(n_particles):
            velocities[i] = [update_velocity(pbest[i][j], gbest[j], particles[i][j], w, c1, c2) for j in range(len(bounds))]
            particles[i] = [update_position(particles[i][j], velocities[i][j]) for j in range(len(bounds))]
        for i in range(n_particles):
            if f(particles[i]) < f(pbest[i]):
                pbest[i] = particles[i]
        gbest = min(particles, key=f)

def main():

    def objective(x):
        return sum((xi ** 2 for xi in x))
    bounds = [(-10, 10)] * 2
    swarm_search(objective, bounds, 30, 0.7, 1.5, 1.5)
main()