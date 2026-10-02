def optimize():
    import random
    n, d, p = (10, 3, 0.1)
    particles = [[random.random() for _ in range(d)] for _ in range(n)]
    for _ in range(100):
        velocities = [[random.random() for _ in range(d)] for _ in range(n)]
        for i in range(n):
            for j in range(d):
                particles[i][j] += velocities[i][j] * p
    return particles
optimize()