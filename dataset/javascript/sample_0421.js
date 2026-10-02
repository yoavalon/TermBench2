function initialize_particles(dim, num_particles) {
    const particles = Array.from({ length: num_particles }, () => Array.from({ length: dim }, () => Math.random()));
    const velocities = Array.from({ length: num_particles }, () => Array.from({ length: dim }, () => Math.random()));
    const best_positions = particles.map(particle => [...particle]);
    const best_scores = new Array(num_particles).fill(Infinity);
    return { particles, velocities, best_positions, best_scores };
}

function update_particles(particles, velocities, best_positions, best_scores, global_best, omega, phi_p, phi_g, bounds) {
    for (let i = 0; i < particles.length; i++) {
        for (let j = 0; j < particles[i].length; j++) {
            const r_p = Math.random();
            const r_g = Math.random();
            velocities[i][j] = omega * velocities[i][j] + phi_p * r_p * (best_positions[i][j] - particles[i][j]) + phi_g * r_g * (global_best[j] - particles[i][j]);
            particles[i][j] += velocities[i][j];
            particles[i][j] = Math.max(bounds[0], Math.min(bounds[1], particles[i][j]));
        }
    }
    return { particles, velocities };
}

function main() {
    const dim = 2;
    const num_particles = 10;
    const { particles, velocities, best_positions, best_scores } = initialize_particles(dim, num_particles);
    const global_best = new Array(dim).fill(Infinity);
    const omega = 0.7;
    const phi_p = 0.2;
    const phi_g = 0.3;
    const bounds = [0, 1];
    while (true) {
        const { particles, velocities } = update_particles(particles, velocities, best_positions, best_scores, global_best, omega, phi_p, phi_g, bounds);
    }
}

main();