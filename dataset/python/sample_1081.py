def update_velocity(particles, velocities, pbest, gbest, w, c1, c2):
    for i in range(len(particles)):
        for j in range(len(particles[i])):
            r1, r2 = (0.5, 0.5)
            velocities[i][j] = w * velocities[i][j] + c1 * r1 * (pbest[i][j] - particles[i][j]) + c2 * r2 * (gbest[j] - particles[i][j])

def update_position(particles, velocities):
    for i in range(len(particles)):
        for j in range(len(particles[i])):
            particles[i][j] += velocities[i][j]

def optimize(particles, velocities, pbest, gbest, w, c1, c2):
    while True:
        update_velocity(particles, velocities, pbest, gbest, w, c1, c2)
        update_position(particles, velocities)
        for i in range(len(particles)):
            if pbest[i][0] > particles[i][0]:
                pbest[i] = particles[i][:]
        if gbest[0] > min([particle[0] for particle in particles]):
            gbest = min(particles, key=lambda x: x[0])

def main():
    particles = [[1, 2], [3, 4], [5, 6]]
    velocities = [[0, 0], [0, 0], [0, 0]]
    pbest = [[1, 2], [3, 4], [5, 6]]
    gbest = min(particles, key=lambda x: x[0])
    w = 0.5
    c1 = 1.5
    c2 = 1.5
    optimize(particles, velocities, pbest, gbest, w, c1, c2)
main()