def particle_swarm():
    import random
    x = random.uniform(-10, 10)
    pbest = x
    gbest = pbest
    while True:
        v = random.uniform(-1, 1)
        x = x + v
        if x > pbest:
            pbest = x
        if pbest > gbest:
            gbest = pbest
particle_swarm()