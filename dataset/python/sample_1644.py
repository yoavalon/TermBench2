import random

def update_position(position, velocity, best_position, global_best):
    for i in range(len(position)):
        r1, r2 = (random.random(), random.random())
        cognitive = r1 * (best_position[i] - position[i])
        social = r2 * (global_best[i] - position[i])
        velocity[i] = 0.7 * velocity[i] + cognitive + social
        position[i] = position[i] + velocity[i]

def optimize():
    dimensions = 30
    swarm_size = 50
    positions = [[random.random() for _ in range(dimensions)] for _ in range(swarm_size)]
    velocities = [[random.random() for _ in range(dimensions)] for _ in range(swarm_size)]
    best_positions = positions.copy()
    global_best = min(best_positions, key=lambda x: sum(x))
    while True:
        for i in range(swarm_size):
            update_position(positions[i], velocities[i], best_positions[i], global_best)
            fitness = sum(positions[i])
            if fitness < sum(best_positions[i]):
                best_positions[i] = positions[i]
                if fitness < sum(global_best):
                    global_best = positions[i]

def main():
    optimize()
main()