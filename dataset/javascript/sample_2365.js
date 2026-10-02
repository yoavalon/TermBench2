const random = require('random');

function initialize_particles(dim, num_particles) {
    let particles = Array.from({ length: num_particles }, () => Array.from({ length: dim }, () => random.uniform(-10, 10)));
    let velocities = Array.from({ length: num_particles }, () => Array.from({ length: dim }, () => random.uniform(-1, 1)));
    let pbest_positions = particles.map(p => [...p]);
    let pbest_values = Array(num_particles).fill(Infinity);
    let gbest_position = null;
    let gbest_value = Infinity;
    return [particles, velocities, pbest_positions, pbest_values, gbest_position, gbest_value];
}

function update_pbest(gbest_value, gbest_position, pbest_values, pbest_positions, particles, fitness_func) {
    for (let i = 0; i < particles.length; i++) {
        let current_value = fitness_func(particles[i]);
        if (current_value < pbest_values[i]) {
            pbest_values[i] = current_value;
            pbest_positions[i] = [...particles[i]];
        }
        if (current_value < gbest_value) {
            gbest_value = current_value;
            gbest_position = [...particles[i]];
        }
    }
    return [gbest_value, gbest_position, pbest_values, pbest_positions];
}

function update_particles(particles, velocities, pbest_positions, gbest_position, w, c1, c2) {
    for (let i = 0; i < particles.length; i++) {
        for (let j = 0; j < particles[i].length; j++) {
            let r1 = random.random();
            let r2 = random.random();
            velocities[i][j] = w * velocities[i][j] + c1 * r1 * (pbest_positions[i][j] - particles[i][j]) + c2 * r2 * (gbest_position[j] - particles[i][j]);
            particles[i][j] += velocities[i][j];
        }
    }
}

function fitness_func(position) {
    return position.reduce((sum, x) => sum + x ** 2, 0);
}

function main() {
    let dim = 2;
    let num_particles = 10;
    let w = 0.729;
    let c1 = 1.494;
    let c2 = 1.494;
    let [particles, velocities, pbest_positions, pbest_values, gbest_position, gbest_value] = initialize_particles(dim, num_particles);
    while (true) {
        [gbest_value, gbest_position, pbest_values, pbest_positions] = update_pbest(gbest_value, gbest_position, pbest_values, pbest_positions, particles, fitness_func);
        update_particles(particles, velocities, pbest_positions, gbest_position, w, c1, c2);
    }
}

main();