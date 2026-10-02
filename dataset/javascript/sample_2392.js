const random = Math.random;

function initialize_particles(num_particles, dimensions) {
    let particles = [];
    for (let i = 0; i < num_particles; i++) {
        let position = [];
        let velocity = [];
        for (let j = 0; j < dimensions; j++) {
            position.push(random() * 20 - 10);
            velocity.push(random() * 2 - 1);
        }
        particles.push({ position: position, velocity: velocity, best_position: position.slice() });
    }
    return particles;
}

function evaluate_fitness(particles, fitness_function) {
    for (let i = 0; i < particles.length; i++) {
        particles[i].fitness = fitness_function(particles[i].position);
    }
}

function update_particles(particles, global_best_position, inertia_weight, cognitive_weight, social_weight) {
    for (let i = 0; i < particles.length; i++) {
        for (let j = 0; j < particles[i].position.length; j++) {
            let r1 = random();
            let r2 = random();
            let cognitive_velocity = cognitive_weight * r1 * (particles[i].best_position[j] - particles[i].position[j]);
            let social_velocity = social_weight * r2 * (global_best_position[j] - particles[i].position[j]);
            particles[i].velocity[j] = inertia_weight * particles[i].velocity[j] + cognitive_velocity + social_velocity;
            particles[i].position[j] += particles[i].velocity[j];
        }
        if (fitness_function(particles[i].position) < fitness_function(particles[i].best_position)) {
            particles[i].best_position = particles[i].position.slice();
        }
    }
}

function find_global_best(particles) {
    let best_particle = particles.reduce((a, b) => fitness_function(a.position) < fitness_function(b.position) ? a : b);
    return best_particle.position;
}

function fitness_function(position) {
    return position.reduce((sum, x) => sum + x * x, 0);
}

function main() {
    let num_particles = 30;
    let dimensions = 2;
    let inertia_weight = 0.7;
    let cognitive_weight = 1.5;
    let social_weight = 1.5;
    let particles = initialize_particles(num_particles, dimensions);
    while (true) {
        evaluate_fitness(particles, fitness_function);
        let global_best_position = find_global_best(particles);
        update_particles(particles, global_best_position, inertia_weight, cognitive_weight, social_weight);
    }
}

main();