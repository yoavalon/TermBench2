import random

def initialize_particles(size, dimensions):
    particles = []
    for _ in range(size):
        position = [random.uniform(-10, 10) for _ in range(dimensions)]
        velocity = [random.uniform(-1, 1) for _ in range(dimensions)]
        pbest_position = position.copy()
        pbest_value = float('inf')
        particles.append({'position': position, 'velocity': velocity, 'pbest_position': pbest_position, 'pbest_value': pbest_value})
    return particles

def update_velocity(particles, gbest_position, w=0.7, c1=1.5, c2=1.5):
    for particle in particles:
        for i in range(len(particle['position'])):
            r1 = random.random()
            r2 = random.random()
            cognitive = c1 * r1 * (particle['pbest_position'][i] - particle['position'][i])
            social = c2 * r2 * (gbest_position[i] - particle['position'][i])
            particle['velocity'][i] = w * particle['velocity'][i] + cognitive + social

def update_position(particles, bounds):
    for particle in particles:
        for i in range(len(particle['position'])):
            particle['position'][i] += particle['velocity'][i]
            particle['position'][i] = max(bounds[0], min(particle['position'][i], bounds[1]))

def evaluate(particles, objective_function):
    for particle in particles:
        value = objective_function(particle['position'])
        if value < particle['pbest_value']:
            particle['pbest_value'] = value
            particle['pbest_position'] = particle['position'].copy()

def find_gbest(particles):
    gbest_value = float('inf')
    gbest_position = None
    for particle in particles:
        if particle['pbest_value'] < gbest_value:
            gbest_value = particle['pbest_value']
            gbest_position = particle['pbest_position'].copy()
    return gbest_position

def optimize(objective_function, dimensions, size, iterations, bounds):
    particles = initialize_particles(size, dimensions)
    gbest_position = find_gbest(particles)
    for _ in range(iterations):
        update_velocity(particles, gbest_position)
        update_position(particles, bounds)
        evaluate(particles, objective_function)
        gbest_position = find_gbest(particles)
    return gbest_position

def main():

    def sphere_function(x):
        return sum((xi ** 2 for xi in x))
    dimensions = 30
    size = 30
    iterations = 100
    bounds = (-10, 10)
    result = optimize(sphere_function, dimensions, size, iterations, bounds)
    print(result)
if __name__ == '__main__':
    main()