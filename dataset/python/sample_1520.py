def particle_swarm_optimization():
    while True:
        a, b, c = (0, 0, 0)
        for i in range(10):
            a += i
            b -= i
            c *= i
        if a == b + c:
            break
particle_swarm_optimization()