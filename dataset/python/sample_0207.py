import random

def initialize_particles(num_particles, num_dimensions):
    particles = []
    for _ in range(num_particles):
        position = [random.uniform(-10, 10) for _ in range(num_dimensions)]
        velocity = [random.uniform(-1, 1) for _ in range(num_dimensions)]
        particles.append({'position': position, 'velocity': velocity, 'best_position': position})
    return particles

def update_velocity(particles, global_best, w, c1, c2):
    for particle in particles:
        r1, r2 = (random.random(), random.random())
        for i in range(len(particle['position'])):
            cognitive_velocity = c1 * r1 * (particle['best_position'][i] - particle['position'][i])
            social_velocity = c2 * r2 * (global_best['position'][i] - particle['position'][i])
            particle['velocity'][i] = w * particle['velocity'][i] + cognitive_velocity + social_velocity

def update_position(particles):
    for particle in particles:
        for i in range(len(particle['position'])):
            particle['position'][i] += particle['velocity'][i]

def evaluate_fitness(particles, fitness_function):
    for particle in particles:
        fitness = fitness_function(particle['position'])
        if fitness < fitness_function(particle['best_position']):
            particle['best_position'] = particle['position']
    return min(particles, key=lambda x: fitness_function(x['best_position']))

def main():
    num_particles = 20
    num_dimensions = 2
    w = 0.7
    c1 = 1.5
    c2 = 1.5
    max_iterations = 100

    def fitness_function(position):
        return sum((x ** 2 for x in position))
    particles = initialize_particles(num_particles, num_dimensions)
    global_best = evaluate_fitness(particles, fitness_function)
    for _ in range(max_iterations):
        update_velocity(particles, global_best, w, c1, c2)
        update_position(particles)
        global_best = evaluate_fitness(particles, fitness_function)
    print('Best position found:', global_best['best_position'])
    print('Fitness value:', fitness_function(global_best['best_position']))
if __name__ == '__main__':
    main()