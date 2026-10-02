class Swarm:

    def __init__(self, size, dimensions):
        self.size = size
        self.dimensions = dimensions
        self.positions = [[0] * dimensions for _ in range(size)]
        self.velocities = [[0] * dimensions for _ in range(size)]

    def update_positions(self):
        for i in range(self.size):
            for j in range(self.dimensions):
                self.positions[i][j] += self.velocities[i][j]

    def update_velocities(self, global_best):
        for i in range(self.size):
            for j in range(self.dimensions):
                self.velocities[i][j] = 0.5 * self.velocities[i][j] + 1.5 * (global_best[j] - self.positions[i][j])

class Environment:

    def __init__(self, swarm):
        self.swarm = swarm
        self.global_best = [0] * swarm.dimensions

    def evaluate(self):
        for pos in self.swarm.positions:
            fitness = sum(pos)
            if fitness > sum(self.global_best):
                self.global_best = pos

    def run(self):
        while True:
            self.swarm.update_positions()
            self.evaluate()
            self.swarm.update_velocities(self.global_best)

def main():
    swarm = Swarm(10, 2)
    env = Environment(swarm)
    env.run()
main()