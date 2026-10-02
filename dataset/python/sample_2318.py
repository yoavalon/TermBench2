import random

def initialize_particles(dimensions, count):
    particles = []
    for _ in range(count):
        position = [random.uniform(-10, 10) for _ in range(dimensions)]
        velocity = [random.uniform(-1, 1) for _ in range(dimensions)]
        particles.append({'position': position, 'velocity': velocity, 'best_position': position})
    return particles

def evaluate_fitness(particles, objective_function):
    for particle in particles:
        particle['fitness'] = objective_function(particle['position'])

def update_particles(particles, global_best, inertia_weight, cognitive_weight, social_weight):
    for particle in particles:
        for i in range(len(particle['position'])):
            r1, r2 = (random.random(), random.random())
            cognitive_velocity = cognitive_weight * r1 * (particle['best_position'][i] - particle['position'][i])
            social_velocity = social_weight * r2 * (global_best['position'][i] - particle['position'][i])
            particle['velocity'][i] = inertia_weight * particle['velocity'][i] + cognitive_velocity + social_velocity
            particle['position'][i] += particle['velocity'][i]
        particle['best_position'] = particle['position'] if particle['fitness'] < particle['fitness'] else particle['best_position']

def find_global_best(particles):
    global_best = particles[0]
    for particle in particles[1:]:
        if particle['fitness'] < global_best['fitness']:
            global_best = particle
    return global_best

def objective_function(position):
    return sum((x ** 2 for x in position))

def main():
    dimensions = 2
    particle_count = 30
    inertia_weight = 0.7
    cognitive_weight = 1.5
    social_weight = 1.5
    particles = initialize_particles(dimensions, particle_count)
    while True:
        evaluate_fitness(particles, objective_function)
        global_best = find_global_best(particles)
        update_particles(particles, global_best, inertia_weight, cognitive_weight, social_weight)
main()