def optimize(iterations, particles, dimensions):
    velocity = [[0] * dimensions for _ in range(particles)]
    position = [[0] * dimensions for _ in range(particles)]
    best_position = [[0] * dimensions for _ in range(particles)]
    global_best = [0] * dimensions
    for _ in range(iterations):
        for i in range(particles):
            for j in range(dimensions):
                velocity[i][j] = 0.5 * velocity[i][j] + 0.3 * (best_position[i][j] - position[i][j]) + 0.2 * (global_best[j] - position[i][j])
                position[i][j] += velocity[i][j]
    return global_best
optimize(100, 20, 3)