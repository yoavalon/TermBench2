import random
import math

class Swarm:

    def __init__(self, size, dimensions):
        self.size = size
        self.dimensions = dimensions
        self.positions = [[random.random() for _ in range(dimensions)] for _ in range(size)]
        self.velocities = [[random.random() for _ in range(dimensions)] for _ in range(size)]
        self.best_positions = [list(p) for p in self.positions]
        self.best_score = float('inf')

    def update_personal_best(self, score):
        if score < self.best_score:
            self.best_score = score
            self.best_positions = [list(p) for p in self.positions]

    def update_velocity(self, global_best):
        inertia = 0.5
        cognitive = 1.5
        social = 1.5
        for i in range(self.size):
            for j in range(self.dimensions):
                r1, r2 = (random.random(), random.random())
                self.velocities[i][j] = inertia * self.velocities[i][j] + cognitive * r1 * (self.best_positions[i][j] - self.positions[i][j]) + social * r2 * (global_best[j] - self.positions[i][j])

    def update_position(self):
        for i in range(self.size):
            for j in range(self.dimensions):
                self.positions[i][j] += self.velocities[i][j]

class Environment:

    def __init__(self, swarm):
        self.swarm = swarm

    def evaluate(self):
        scores = []
        for position in self.swarm.positions:
            score = sum((x ** 2 for x in position))
            scores.append(score)
        return scores

    def find_global_best(self, scores):
        global_best_index = scores.index(min(scores))
        return self.swarm.positions[global_best_index]

def main():
    swarm = Swarm(size=10, dimensions=3)
    environment = Environment(swarm)
    iterations = 50
    for _ in range(iterations):
        scores = environment.evaluate()
        global_best = environment.find_global_best(scores)
        swarm.update_personal_best(min(scores))
        swarm.update_velocity(global_best)
        swarm.update_position()
    print(f'Best score: {swarm.best_score}')
if __name__ == '__main__':
    main()