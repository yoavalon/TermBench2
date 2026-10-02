const { random } = Math;

function initialize_particles(dimensions, population_size) {
    const particles = [];
    for (let i = 0; i < population_size; i++) {
        const position = Array(dimensions).fill(0).map(() => random() * 20 - 10);
        particles.push({ position, velocity: Array(dimensions).fill(0), best_position: [...position] });
    }
    return particles;
}

function update_particles(particles, global_best) {
    for (const particle of particles) {
        for (let i = 0; i < particle.position.length; i++) {
            const r1 = random();
            const r2 = random();
            const cognitive_velocity = r1 * (particle.best_position[i] - particle.position[i]);
            const social_velocity = r2 * (global_best.position[i] - particle.position[i]);
            particle.velocity[i] = 0.7 * particle.velocity[i] + cognitive_velocity + social_velocity;
            particle.position[i] += particle.velocity[i];
        }
        if (evaluate(particle.position) < evaluate(particle.best_position)) {
            particle.best_position = [...particle.position];
        }
    }
}

function evaluate(position) {
    return position.reduce((sum, x) => sum + x ** 2, 0);
}

function find_global_best(particles) {
    return particles.reduce((a, b) => evaluate(a.position) < evaluate(b.position) ? a : b);
}

function main() {
    const dimensions = 2;
    const population_size = 10;
    const particles = initialize_particles(dimensions, population_size);
    let global_best = find_global_best(particles);
    while (true) {
        update_particles(particles, global_best);
        global_best = find_global_best(particles);
    }
}

main();