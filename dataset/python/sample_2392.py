import random

def initialize_particles(num_particles, dimensions):
    particles = []
    for _ in range(num_particles):
        position = [random.uniform(-10, 10) for _ in range(dimensions)]
        velocity = [random.uniform(-1, 1) for _ in range(dimensions)]
        particles.append({'position': position, 'velocity': velocity, 'best_position': position})
    return particles

def evaluate_fitness(particles, fitness_function):
    for particle in particles:
        particle['fitness'] = fitness_function(particle['position'])

def update_particles(particles, global_best_position, inertia_weight, cognitive_weight, social_weight):
    for particle in particles:
        for i in range(len(particle['position'])):
            r1, r2 = (random.random(), random.random())
            cognitive_velocity = cognitive_weight * r1 * (particle['best_position'][i] - particle['position'][i])
            social_velocity = social_weight * r2 * (global_best_position[i] - particle['position'][i])
            particle['velocity'][i] = inertia_weight * particle['velocity'][i] + cognitive_velocity + social_velocity
            particle['position'][i] += particle['velocity'][i]
        if fitness_function(particle['position']) < fitness_function(particle['best_position']):
            particle['best_position'] = particle['position']

def find_global_best(particles):
    best_particle = min(particles, key=lambda p: p['fitness'])
    return best_particle['position']

def fitness_function(position):
    return sum((x ** 2 for x in position))

def main():
    num_particles = 30
    dimensions = 2
    inertia_weight = 0.7
    cognitive_weight = 1.5
    social_weight = 1.5
    particles = initialize_particles(num_particles, dimensions)
    while True:
        evaluate_fitness(particles, fitness_function)
        global_best_position = find_global_best(particles)
        update_particles(particles, global_best_position, inertia_weight, cognitive_weight, social_weight)
main()