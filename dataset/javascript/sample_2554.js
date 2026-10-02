function initialize_particles(num_particles, dimensions) {
    let particles = [];
    for (let i = 0; i < num_particles; i++) {
        let particle = [];
        for (let j = 0; j < dimensions; j++) {
            particle.push(Math.random() * 2 - 1);
        }
        particles.push(particle);
    }
    return particles;
}

function evaluate_fitness(position, target) {
    return position.reduce((sum, p, i) => sum + Math.pow(p - target[i], 2), 0);
}

function update_velocity(velocity, position, p_best, g_best, w, c1, c2) {
    let new_velocity = [];
    for (let i = 0; i < velocity.length; i++) {
        let r1 = Math.random();
        let r2 = Math.random();
        new_velocity.push(w * velocity[i] + c1 * r1 * (p_best[i] - position[i]) + c2 * r2 * (g_best[i] - position[i]));
    }
    return new_velocity;
}

function update_position(position, velocity) {
    return position.map((x, i) => x + velocity[i]);
}

function particle_swarm(num_particles, dimensions, target, max_iterations) {
    let particles = initialize_particles(num_particles, dimensions);
    let velocities = Array(num_particles).fill().map(() => Array(dimensions).fill(0));
    let p_best = [...particles];
    let g_best = particles.reduce((best, particle) => evaluate_fitness(particle, target) < evaluate_fitness(best, target) ? particle : best);

    for (let iteration = 0; iteration < max_iterations; iteration++) {
        for (let i = 0; i < num_particles; i++) {
            if (evaluate_fitness(particles[i], target) < evaluate_fitness(p_best[i], target)) {
                p_best[i] = particles[i];
            }
        }
        g_best = p_best.reduce((best, particle) => evaluate_fitness(particle, target) < evaluate_fitness(best, target) ? particle : best);

        for (let i = 0; i < num_particles; i++) {
            velocities[i] = update_velocity(velocities[i], particles[i], p_best[i], g_best, 0.7, 1.5, 1.5);
            particles[i] = update_position(particles[i], velocities[i]);
        }
    }
    return g_best;
}

function main() {
    let target = [0, 0];
    let result = particle_swarm(30, 2, target, 100);
    console.log(result);
}

main();