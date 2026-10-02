import random

def fitness_function(x):
    return x ** 2

def update_position(position, velocity, w, c1, c2, pbest, gbest):
    r1, r2 = (random.random(), random.random())
    velocity = w * velocity + c1 * r1 * (pbest - position) + c2 * r2 * (gbest - position)
    position = position + velocity
    return (position, velocity)

def optimize(iterations, w, c1, c2, bounds):
    particles = [random.uniform(bounds[0], bounds[1]) for _ in range(30)]
    velocities = [0 for _ in range(30)]
    pbests = particles[:]
    gbest = min(particles, key=fitness_function)
    for _ in range(iterations):
        for i in range(len(particles)):
            particles[i], velocities[i] = update_position(particles[i], velocities[i], w, c1, c2, pbests[i], gbest)
            if fitness_function(particles[i]) < fitness_function(pbests[i]):
                pbests[i] = particles[i]
        gbest = min(particles, key=fitness_function)
    return gbest

def main():
    iterations = 100
    w = 0.7
    c1 = 1.5
    c2 = 1.5
    bounds = [-10, 10]
    result = optimize(iterations, w, c1, c2, bounds)
    print(result)
main()