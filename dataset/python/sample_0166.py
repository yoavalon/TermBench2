import random

def initialize_particles(num_particles, dimensions, bounds):
    particles = []
    for _ in range(num_particles):
        particle = [random.uniform(bounds[0], bounds[1]) for _ in range(dimensions)]
        particles.append(particle)
    return particles

def update_positions(particles, velocities, bounds):
    new_positions = []
    for i in range(len(particles)):
        new_position = [max(bounds[0], min(bounds[1], particles[i][j] + velocities[i][j])) for j in range(len(particles[i]))]
        new_positions.append(new_position)
    return new_positions

def main():
    num_particles = 30
    dimensions = 2
    bounds = [0, 10]
    particles = initialize_particles(num_particles, dimensions, bounds)
    velocities = [[random.uniform(-1, 1) for _ in range(dimensions)] for _ in range(num_particles)]
    for _ in range(100):
        particles = update_positions(particles, velocities, bounds)
    print(particles)
if __name__ == '__main__':
    main()