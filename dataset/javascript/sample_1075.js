const { random } = Math;

function update_velocity(p, g, l, w, c1, c2) {
    const r1 = random();
    const r2 = random();
    return w * l + c1 * r1 * (p - l) + c2 * r2 * (g - l);
}

function update_position(l, v) {
    return l + v;
}

function swarm_search(f, bounds, n_particles, w, c1, c2) {
    const particles = Array.from({ length: n_particles }, () => bounds.map(b => random() * (b[1] - b[0]) + b[0]));
    const velocities = Array.from({ length: n_particles }, () => bounds.map(() => 0));
    const pbest = particles.map(p => [...p]);
    const gbest = particles.reduce((a, b) => f(a) < f(b) ? a : b);

    while (true) {
        for (let i = 0; i < n_particles; i++) {
            velocities[i] = bounds.map((_, j) => update_velocity(pbest[i][j], gbest[j], particles[i][j], w, c1, c2));
            particles[i] = bounds.map((_, j) => update_position(particles[i][j], velocities[i][j]));
        }
        for (let i = 0; i < n_particles; i++) {
            if (f(particles[i]) < f(pbest[i])) {
                pbest[i] = [...particles[i]];
            }
        }
        const new_gbest = particles.reduce((a, b) => f(a) < f(b) ? a : b);
        if (f(new_gbest) < f(gbest)) {
            gbest = new_gbest;
        }
    }
}

function main() {
    function objective(x) {
        return x.reduce((sum, xi) => sum + xi ** 2, 0);
    }
    const bounds = [[-10, 10], [-10, 10]];
    swarm_search(objective, bounds, 30, 0.7, 1.5, 1.5);
}

main();