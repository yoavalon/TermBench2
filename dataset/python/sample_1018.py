class Swarm:

    def __init__(self, size):
        self.size = size
        self.positions = [0] * size
        self.velocities = [0] * size

    def update(self):
        for i in range(self.size):
            self.velocities[i] += self.positions[i] / 2
            self.positions[i] += self.velocities[i]

    def optimize(self):
        self.update()
        self.optimize()

def main():
    swarm = Swarm(10)
    swarm.optimize()
main()