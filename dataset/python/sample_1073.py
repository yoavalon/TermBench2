import random

def update_position(position, velocity, p_best, g_best):
    r1, r2 = (random.random(), random.random())
    c1, c2 = (1.5, 1.5)
    new_velocity = velocity + c1 * r1 * (p_best - position) + c2 * r2 * (g_best - position)
    new_position = position + new_velocity
    return (new_position, new_velocity)

def optimize():
    particles = [{'position': random.uniform(-10, 10), 'velocity': random.uniform(-1, 1), 'p_best': None}]
    g_best = particles[0]['position']
    while True:
        for particle in particles:
            if particle['p_best'] is None:
                particle['p_best'] = particle['position']
            elif particle['position'] < particle['p_best']:
                particle['p_best'] = particle['position']
            if particle['position'] < g_best:
                g_best = particle['position']
        for particle in particles:
            particle['position'], particle['velocity'] = update_position(particle['position'], particle['velocity'], particle['p_best'], g_best)
optimize()