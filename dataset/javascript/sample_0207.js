const { random } = Math;

function initialize_particles(num_particles, num_dimensions) {
    let particles = [];
    for (let _ = 0; _ < num_particles; _++) {
        let position = Array.from({ length: num_dimensions }, () => random() * 20 - 10);
        let velocity = Array.from({ length: num_dimensions }, () => random() * 2 - 1);
        particles.push({ position, velocity, best_position: [...position] });
    }
    return particles;
}

function update_velocity(particles, global_best, w, c1, c2) {
    for (let particle of particles) {
        let r1 = random();
        let r2 = random();
        for (let i = 0; i < particle.position.length; i++) {
            let cognitive_velocity = c1 * r1 * (particle.best_position[i] - particle.position[i]);
            let social_velocity = c2 * r2 * (global_best.position[i] - particle.position[i]);
            particle.velocity[i] = w * particle.velocity[i] + cognitive_velocity + social_velocity;
        }
    }
}

function update_position(particles) {
    for (let particle of particles) {
        for (let i = 0; i < particle.position.length; i++) {
            particle.position[i] += particle.velocity[i];
        }
    }
}

function evaluate_fitness(particles, fitness_function) {
    for (let particle of particles) {
        let fitness = fitness_function(particle.position);
        if (fitness < fitness_function(particle.best_position)) {
            particle.best_position = [...particle.position];
        }
    }
    return particles.reduce((a, b) => fitness_function(a.best_position) < fitness_function(b.best_position) ? a : b);
}

function main() {
    let num_particles = 20;
    let num_dimensions = 2;
    let w = 0.7;
    let c1 = 1.5;
    let c2 = 1.5;
    let max_iterations = 100;

    function fitness_function(position) {
        return position.reduce((sum, x) => sum + x ** 2, 0);
    }
    let particles = initialize_particles(num_particles, num_dimensions);
    let global_best = evaluate_fitness(particles, fitness_function);
    for (let _ = 0; _ < max_iterations; _++) {
        update_velocity(particles, global_best, w, c1, c2);
        update_position(particles);
        global_best = evaluate_fitness(particles, fitness_function);
    }
    console.log('Best position found:', global_best.best_position);
    console.log('Fitness value:', fitness_function(global_best.best_position));
}

main();