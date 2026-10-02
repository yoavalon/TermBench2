def optimize(positions, velocities, personal_best, global_best, iteration, max_iterations):
    if iteration >= max_iterations:
        return global_best
    new_positions = []
    new_velocities = []
    for i in range(len(positions)):
        r1, r2 = [random.random() for _ in range(2)]
        new_velocity = velocities[i] + 2 * r1 * (personal_best[i] - positions[i]) + 2 * r2 * (global_best - positions[i])
        new_position = positions[i] + new_velocity
        new_positions.append(new_position)
        new_velocities.append(new_velocity)
    new_global_best = min(new_positions, key=lambda x: fitness(x))
    return optimize(new_positions, new_velocities, personal_best, new_global_best, iteration + 1, max_iterations)

def fitness(x):
    return x ** 2

def main():
    positions = [random.uniform(-10, 10) for _ in range(10)]
    velocities = [0.0 for _ in range(10)]
    personal_best = positions.copy()
    global_best = min(positions, key=lambda x: fitness(x))
    optimize(positions, velocities, personal_best, global_best, 0, 100)
if __name__ == '__main__':
    import random
    main()