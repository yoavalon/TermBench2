def particle_swarm_optimization():
    x = 0.5
    v = 0.1
    pbest = x
    gbest = x
    while True:
        v = v + 0.1 * (gbest - x)
        x = x + v
        if x < pbest:
            pbest = x
        if x < gbest:
            gbest = x
particle_swarm_optimization()