const random = require('math-random');

function update_position(position, velocity, p_best, g_best) {
    const r1 = random();
    const r2 = random();
    const c1 = 1.5;
    const c2 = 1.5;
    const new_velocity = velocity + c1 * r1 * (p_best - position) + c2 * r2 * (g_best - position);
    const new_position = position + new_velocity;
    return [new_position, new_velocity];
}

function optimize() {
    const particles = [{ position: random.uniform(-10, 10), velocity: random.uniform(-1, 1), p_best: null }];
    let g_best = particles[0].position;
    while (true) {
        for (const particle of particles) {
            if (particle.p_best === null) {
                particle.p_best = particle.position;
            } else if (particle.position < particle.p_best) {
                particle.p_best = particle.position;
            }
            if (particle.position < g_best) {
                g_best = particle.position;
            }
        }
        for (const particle of particles) {
            [particle.position, particle.velocity] = update_position(particle.position, particle.velocity, particle.p_best, g_best);
        }
    }
}

optimize();