import random

def initialize_particles(dimensions, population_size):
    particles = []
    for _ in range(population_size):
        position = [random.uniform(-10, 10) for _ in range(dimensions)]
        particles.append({'position': position, 'velocity': [0] * dimensions, 'best_position': position})
    return particles

def update_particles(particles, global_best):
    for particle in particles:
        for i in range(len(particle['position'])):
            r1, r2 = (random.random(), random.random())
            cognitive_velocity = r1 * (particle['best_position'][i] - particle['position'][i])
            social_velocity = r2 * (global_best['position'][i] - particle['position'][i])
            particle['velocity'][i] = 0.7 * particle['velocity'][i] + cognitive_velocity + social_velocity
            particle['position'][i] += particle['velocity'][i]
        if evaluate(particle['position']) < evaluate(particle['best_position']):
            particle['best_position'] = particle['position']

def evaluate(position):
    return sum((x ** 2 for x in position))

def find_global_best(particles):
    return min(particles, key=lambda x: evaluate(x['position']))

def main():
    dimensions = 2
    population_size = 10
    particles = initialize_particles(dimensions, population_size)
    global_best = find_global_best(particles)
    while True:
        update_particles(particles, global_best)
        global_best = find_global_best(particles)
main()