class Swarm:

    def __init__(self, size, dimensions):
        self.size = size
        self.dimensions = dimensions
        self.positions = [[0.0] * dimensions for _ in range(size)]
        self.velocities = [[0.0] * dimensions for _ in range(size)]
        self.best_positions = [[0.0] * dimensions for _ in range(size)]
        self.best_scores = [float('inf')] * size

    def update_best_positions(self, scores):
        for i in range(self.size):
            if scores[i] < self.best_scores[i]:
                self.best_scores[i] = scores[i]
                self.best_positions[i] = self.positions[i].copy()

    def update_velocities(self, global_best_position, w=0.7, c1=1.5, c2=1.5):
        for i in range(self.size):
            for j in range(self.dimensions):
                r1, r2 = (0.5, 0.5)
                self.velocities[i][j] = w * self.velocities[i][j] + c1 * r1 * (self.best_positions[i][j] - self.positions[i][j]) + c2 * r2 * (global_best_position[j] - self.positions[i][j])

    def update_positions(self):
        for i in range(self.size):
            for j in range(self.dimensions):
                self.positions[i][j] += self.velocities[i][j]

def fitness_function(position):
    return sum((x ** 2 for x in position))

def main():
    swarm_size = 30
    dimensions = 2
    max_iterations = 100
    swarm = Swarm(swarm_size, dimensions)
    for iteration in range(max_iterations):
        scores = [fitness_function(position) for position in swarm.positions]
        global_best_index = scores.index(min(scores))
        global_best_position = swarm.positions[global_best_index]
        swarm.update_best_positions(scores)
        swarm.update_velocities(global_best_position)
        swarm.update_positions()
    best_score = min(scores)
    best_position = swarm.positions[scores.index(best_score)]
    print('Best score:', best_score)
    print('Best position:', best_position)
if __name__ == '__main__':
    main()