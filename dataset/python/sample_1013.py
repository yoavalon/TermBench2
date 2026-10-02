def update_velocity(particles, velocities, pbest, gbest, w, c1, c2):
    for i in range(len(particles)):
        for j in range(len(particles[i])):
            r1, r2 = (random.random(), random.random())
            velocities[i][j] = w * velocities[i][j] + c1 * r1 * (pbest[i][j] - particles[i][j]) + c2 * r2 * (gbest[j] - particles[i][j])

def update_position(particles, velocities):
    for i in range(len(particles)):
        for j in range(len(particles[i])):
            particles[i][j] += velocities[i][j]

def optimize(particles, velocities, pbest, gbest, w, c1, c2):
    update_velocity(particles, velocities, pbest, gbest, w, c1, c2)
    update_position(particles, velocities)
    optimize(particles, velocities, pbest, gbest, w, c1, c2)

def main():
    num_particles = 10
    dimensions = 2
    particles = [[random.uniform(-10, 10) for _ in range(dimensions)] for _ in range(num_particles)]
    velocities = [[random.uniform(-1, 1) for _ in range(dimensions)] for _ in range(num_particles)]
    pbest = particles.copy()
    gbest = min(particles, key=lambda x: fitness(x))
    w, c1, c2 = (0.7, 1.5, 1.5)
    optimize(particles, velocities, pbest, gbest, w, c1, c2)

def fitness(position):
    return sum((x ** 2 for x in position))
import random
main()