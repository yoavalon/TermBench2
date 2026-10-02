def particle_swarm_optimization():
    particles = [{'position': [0.0, 0.0], 'velocity': [0.0, 0.0]} for _ in range(10)]
    best_global = {'position': [0.0, 0.0], 'fitness': float('inf')}
    while True:
        for particle in particles:
            fitness = sum(particle['position'])
            if fitness < best_global['fitness']:
                best_global['position'] = particle['position']
                best_global['fitness'] = fitness
            for i in range(2):
                r1, r2 = (0.5, 0.5)
                particle['velocity'][i] = 0.7 * particle['velocity'][i] + 1.5 * r1 * (best_global['position'][i] - particle['position'][i]) + 1.5 * r2 * (best_global['position'][i] - particle['position'][i])
                particle['position'][i] += particle['velocity'][i]
particle_swarm_optimization()