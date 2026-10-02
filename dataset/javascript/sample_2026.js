const { random } = Math;

function initialize_particles(size, dimensions) {
    const particles = [];
    for (let _ = 0; _ < size; _++) {
        const position = Array.from({ length: dimensions }, () => random() * 20 - 10);
        const velocity = Array.from({ length: dimensions }, () => random() * 2 - 1);
        const pbest_position = position.slice();
        const pbest_value = Infinity;
        particles.push({ position, velocity, pbest_position, pbest_value });
    }
    return particles;
}

function update_velocity(particles, gbest_position, w = 0.7, c1 = 1.5, c2 = 1.5) {
    for (const particle of particles) {
        for (let i = 0; i < particle.position.length; i++) {
            const r1 = random();
            const r2 = random();
            const cognitive = c1 * r1 * (particle.pbest_position[i] - particle.position[i]);
            const social = c2 * r2 * (gbest_position[i] - particle.position[i]);
            particle.velocity[i] = w * particle.velocity[i] + cognitive + social;
        }
    }
}

function update_position(particles, bounds) {
    for (const particle of particles) {
        for (let i = 0; i < particle.position.length; i++) {
            particle.position[i] += particle.velocity[i];
            particle.position[i] = Math.max(bounds[0], Math.min(particle.position[i], bounds[1]));
        }
    }
}

function evaluate(particles, objective_function) {
    for (const particle of particles) {
        const value = objective_function(particle.position);
        if (value < particle.pbest_value) {
            particle.pbest_value = value;
            particle.pbest_position = particle.position.slice();
        }
    }
}

function find_gbest(particles) {
    let gbest_value = Infinity;
    let gbest_position = null;
    for (const particle of particles) {
        if (particle.pbest_value < gbest_value) {
            gbest_value = particle.pbest_value;
            gbest_position = particle.pbest_position.slice();
        }
    }
    return gbest_position;
}

function optimize(objective_function, dimensions, size, iterations, bounds) {
    const particles = initialize_particles(size, dimensions);
    let gbest_position = find_gbest(particles);
    for (let _ = 0; _ < iterations; _++) {
        update_velocity(particles, gbest_position);
        update_position(particles, bounds);
        evaluate(particles, objective_function);
        gbest_position = find_gbest(particles);
    }
    return gbest_position;
}

function main() {
    function sphere_function(x) {
        return x.reduce((sum, xi) => sum + xi ** 2, 0);
    }
    const dimensions = 30;
    const size = 30;
    const iterations = 100;
    const bounds = [-10, 10];
    const result = optimize(sphere_function, dimensions, size, iterations, bounds);
    console.log(result);
}

main();