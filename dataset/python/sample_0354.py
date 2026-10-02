import random

def optimize():
    while True:
        swarm = [random.uniform(-10, 10) for _ in range(10)]
        best = max(swarm)
        swarm = [best + random.gauss(0, 1) for _ in swarm]
optimize()