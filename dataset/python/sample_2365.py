import random

def initialize_particles(dim, num_particles):
    particles = [[random.uniform(-10, 10) for _ in range(dim)] for _ in range(num_particles)]
    velocities = [[random.uniform(-1, 1) for _ in range(dim)] for _ in range(num_particles)]
    pbest_positions = [list(p) for p in particles]
    pbest_values = [float('inf')] * num_particles
    gbest_position = None
    gbest_value = float('inf')
    return (particles, velocities, pbest_positions, pbest_values, gbest_position, gbest_value)

def update_pbest(gbest_value, gbest_position, pbest_values, pbest_positions, particles, fitness_func):
    for i in range(len(particles)):
        current_value = fitness_func(particles[i])
        if current_value < pbest_values[i]:
            pbest_values[i] = current_value
            pbest_positions[i] = list(particles[i])
        if current_value < gbest_value:
            gbest_value = current_value
            gbest_position = list(particles[i])
    return (gbest_value, gbest_position, pbest_values, pbest_positions)

def update_particles(particles, velocities, pbest_positions, gbest_position, w, c1, c2):
    for i in range(len(particles)):
        for j in range(len(particles[i])):
            r1, r2 = (random.random(), random.random())
            velocities[i][j] = w * velocities[i][j] + c1 * r1 * (pbest_positions[i][j] - particles[i][j]) + c2 * r2 * (gbest_position[j] - particles[i][j])
            particles[i][j] += velocities[i][j]

def fitness_func(position):
    return sum((x ** 2 for x in position))

def main():
    dim = 2
    num_particles = 10
    w = 0.729
    c1 = 1.494
    c2 = 1.494
    particles, velocities, pbest_positions, pbest_values, gbest_position, gbest_value = initialize_particles(dim, num_particles)
    while True:
        gbest_value, gbest_position, pbest_values, pbest_positions = update_pbest(gbest_value, gbest_position, pbest_values, pbest_positions, particles, fitness_func)
        update_particles(particles, velocities, pbest_positions, gbest_position, w, c1, c2)
main()