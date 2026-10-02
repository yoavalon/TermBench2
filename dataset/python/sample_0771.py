import math

def optimize(positions, velocities, best_positions, global_best, w, c1, c2, iterations, count=0):
    if count == iterations:
        return global_best
    new_velocities = []
    new_positions = []
    for i in range(len(positions)):
        r1, r2 = (random.random(), random.random())
        velocity = w * velocities[i] + c1 * r1 * (best_positions[i] - positions[i]) + c2 * r2 * (global_best - positions[i])
        position = positions[i] + velocity
        new_velocities.append(velocity)
        new_positions.append(position)
    fitnesses = [fitness(position) for position in new_positions]
    best_positions = [new_positions[i] if fitnesses[i] < fitness(best_positions[i]) else best_positions[i] for i in range(len(positions))]
    global_best = min(new_positions, key=fitness) if min(fitnesses) < fitness(global_best) else global_best
    return optimize(new_positions, new_velocities, best_positions, global_best, w, c1, c2, iterations, count + 1)

def fitness(position):
    return math.sin(position) ** 2

def main():
    positions = [random.uniform(-10, 10) for _ in range(10)]
    velocities = [0 for _ in range(10)]
    best_positions = positions[:]
    global_best = min(positions, key=fitness)
    w, c1, c2 = (0.7, 1.5, 1.5)
    iterations = 30
    result = optimize(positions, velocities, best_positions, global_best, w, c1, c2, iterations)
    print(result)
if __name__ == '__main__':
    main()