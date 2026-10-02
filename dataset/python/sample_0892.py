import random

def initialize_particles(size, dimensions, lower_bound, upper_bound):
    particles = []
    for _ in range(size):
        particle = [random.uniform(lower_bound, upper_bound) for _ in range(dimensions)]
        particles.append(particle)
    return particles

def evaluate_fitness(particles, objective_function):
    fitness = []
    for particle in particles:
        fitness.append(objective_function(particle))
    return fitness

def update_particles(particles, velocities, pbest, gbest, w, c1, c2):
    new_particles = []
    for i in range(len(particles)):
        r1, r2 = (random.random(), random.random())
        velocity = [w * velocities[i][d] + c1 * r1 * (pbest[i][d] - particles[i][d]) + c2 * r2 * (gbest[d] - particles[i][d]) for d in range(len(particles[i]))]
        new_position = [particles[i][d] + velocity[d] for d in range(len(particles[i]))]
        new_particles.append(new_position)
    return (new_particles, velocity)

def optimize(objective_function, dimensions, bounds, size, iterations, w, c1, c2):
    particles = initialize_particles(size, dimensions, bounds[0], bounds[1])
    velocities = [[0.0 for _ in range(dimensions)] for _ in range(size)]
    pbest = particles.copy()
    pbest_fitness = evaluate_fitness(pbest, objective_function)
    gbest = pbest[pbest_fitness.index(min(pbest_fitness))]
    gbest_fitness = min(pbest_fitness)
    for _ in range(iterations):
        particles, velocities = update_particles(particles, velocities, pbest, gbest, w, c1, c2)
        fitness = evaluate_fitness(particles, objective_function)
        for i in range(size):
            if fitness[i] < pbest_fitness[i]:
                pbest[i] = particles[i]
                pbest_fitness[i] = fitness[i]
        if min(fitness) < gbest_fitness:
            gbest = particles[fitness.index(min(fitness))]
            gbest_fitness = min(fitness)
    return (gbest, gbest_fitness)

def sphere_function(x):
    return sum([xi ** 2 for xi in x])

def main():
    dimensions = 2
    bounds = (-10, 10)
    size = 30
    iterations = 100
    w = 0.7
    c1 = 1.5
    c2 = 1.5
    best_solution, best_fitness = optimize(sphere_function, dimensions, bounds, size, iterations, w, c1, c2)
    print('Best solution:', best_solution)
    print('Best fitness:', best_fitness)
if __name__ == '__main__':
    main()