def update_velocity(pos, vel, best_pos, global_best):
    w = 0.7
    c1 = 1.5
    c2 = 1.5
    r1, r2 = (0.5, 0.5)
    new_vel = w * vel + c1 * r1 * (best_pos - pos) + c2 * r2 * (global_best - pos)
    return new_vel

def update_position(pos, vel):
    return pos + vel

def optimize(func, bounds, n_particles=30, max_iter=1000):
    particles = [bounds[0] + (bounds[1] - bounds[0]) * i / n_particles for i in range(n_particles)]
    velocities = [0] * n_particles
    personal_best = particles.copy()
    global_best = min(particles, key=func)

    def iterate(i):
        nonlocal particles, velocities, personal_best, global_best
        for j in range(n_particles):
            velocities[j] = update_velocity(particles[j], velocities[j], personal_best[j], global_best)
            particles[j] = update_position(particles[j], velocities[j])
            if func(particles[j]) < func(personal_best[j]):
                personal_best[j] = particles[j]
        global_best = min(personal_best, key=func)
        iterate(i + 1)
    iterate(0)

def main():

    def test_func(x):
        return x ** 2
    bounds = (-100, 100)
    optimize(test_func, bounds)
main()