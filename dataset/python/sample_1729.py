import random

class Swarm:

    def __init__(self, size):
        self.particles = [Particle(random.uniform(-1, 1), random.uniform(-1, 1)) for _ in range(size)]
        self.best = min(self.particles, key=lambda p: p.evaluate())

    def update(self):
        for particle in self.particles:
            particle.update_velocity(self.best)
            particle.move()
        self.best = min(self.particles, key=lambda p: p.evaluate())

class Particle:

    def __init__(self, x, y):
        self.position = [x, y]
        self.velocity = [random.uniform(-0.1, 0.1), random.uniform(-0.1, 0.1)]
        self.best = self.position.copy()

    def evaluate(self):
        return -(self.position[0] ** 2 + self.position[1] ** 2)

    def update_velocity(self, global_best):
        inertia = 0.7
        cognitive = 1.5
        social = 1.5
        for i in range(len(self.velocity)):
            r1, r2 = (random.random(), random.random())
            cognitive_component = cognitive * r1 * (self.best[i] - self.position[i])
            social_component = social * r2 * (global_best.position[i] - self.position[i])
            self.velocity[i] = inertia * self.velocity[i] + cognitive_component + social_component

    def move(self):
        for i in range(len(self.position)):
            self.position[i] += self.velocity[i]
            self.position[i] = max(-1, min(1, self.position[i]))
        if self.evaluate() < self.best[0]:
            self.best = self.position.copy()

def run():
    swarm_size = 30
    swarm = Swarm(swarm_size)
    while True:
        swarm.update()
run()