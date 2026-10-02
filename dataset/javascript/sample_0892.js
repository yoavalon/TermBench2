const random = require('mathjs').random;

function initialize_particles(size, dimensions, lower_bound, upper_bound) {
    let particles = [];
    for (let _ = 0; _ < size; _++) {
        let particle = [];
        for (let _ = 0; _ < dimensions; _++) {
            particle.push(random(lower_bound, upper_bound));
        }
        particles.push(particle);
    }
    return particles;
}

function evaluate_fitness(particles, objective_function) {
    let fitness = [];
    for (let particle of particles) {
        fitness.push(objective_function(particle));
    }
    return fitness;
}

function update_particles(particles, velocities, pbest, gbest, w, c1, c2) {
    let new_particles = [];
    for (let i = 0; i < particles.length; i++) {
        let r1 = random(0, 1);
        let r2 = random(0, 1);
        let velocity = velocities[i].map((v, d) => w * v + c1 * r1 * (pbest[i][d] - particles[i][d]) + c2 * r2 * (gbest[d] - particles[i][d]));
        let new_position = particles[i].map((p, d) => p + velocity[d]);
        new_particles.push(new_position);
    }
    return [new_particles, velocity];
}

function optimize(objective_function, dimensions, bounds, size, iterations, w, c1, c2) {
    let particles = initialize_particles(size, dimensions, bounds[0], bounds[1]);
    let velocities = Array.from({ length: size }, () => Array(dimensions).fill(0.0));
    let pbest = particles.map(p => [...p]);
    let pbest_fitness = evaluate_fitness(pbest, objective_function);
    let gbest = pbest[pbest_fitness.indexOf(Math.min(...pbest_fitness))];
    let gbest_fitness = Math.min(...pbest_fitness);
    for (let _ = 0; _ < iterations; _++) {
        [particles, velocities] = update_particles(particles, velocities, pbest, gbest, w, c1, c2);
        let fitness = evaluate_fitness(particles, objective_function);
        for (let i = 0; i < size; i++) {
            if (fitness[i] < pbest_fitness[i]) {
                pbest[i] = [...particles[i]];
                pbest_fitness[i] = fitness[i];
            }
        }
        if (Math.min(...fitness) < gbest_fitness) {
            gbest = [...particles[fitness.indexOf(Math.min(...fitness))]];
            gbest_fitness = Math.min(...fitness);
        }
    }
    return [gbest, gbest_fitness];
}

function sphere_function(x) {
    return x.reduce((acc, xi) => acc + xi ** 2, 0);
}

function main() {
    let dimensions = 2;
    let bounds = [-10, 10];
    let size = 30;
    let iterations = 100;
    let w = 0.7;
    let c1 = 1.5;
    let c2 = 1.5;
    let [best_solution, best_fitness] = optimize(sphere_function, dimensions, bounds, size, iterations, w, c1, c2);
    console.log('Best solution:', best_solution);
    console.log('Best fitness:', best_fitness);
}

main();