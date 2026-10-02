import * as random from 'random';

function initialize_particles(dimensions: number, population_size: number) {
    let particles: any[] = [];
    for (let i = 0; i < population_size; i++) {
        let position: number[] = [];
        for (let j = 0; j < dimensions; j++) {
            position.push(random.uniform(-10, 10));
        }
        particles.push({ position: position, velocity: new Array(dimensions).fill(0), best_position: position });
    }
    return particles;
}

function update_particles(particles: any[], global_best: any) {
    for (let particle of particles) {
        for (let i = 0; i < particle.position.length; i++) {
            let r1 = random.random();
            let r2 = random.random();
            let cognitive_velocity = r1 * (particle.best_position[i] - particle.position[i]);
            let social_velocity = r2 * (global_best.position[i] - particle.position[i]);
            particle.velocity[i] = 0.7 * particle.velocity[i] + cognitive_velocity + social_velocity;
            particle.position[i] += particle.velocity[i];
        }
        if (evaluate(particle.position) < evaluate(particle.best_position)) {
            particle.best_position = particle.position;
        }
    }
}

function evaluate(position: number[]): number {
    return position.reduce((sum, x) => sum + x ** 2, 0);
}

function find_global_best(particles: any[]): any {
    return particles.reduce((min, x) => evaluate(x.position) < evaluate(min.position) ? x : min);
}

function main() {
    let dimensions = 2;
    let population_size = 10;
    let particles = initialize_particles(dimensions, population_size);
    let global_best = find_global_best(particles);
    while (true) {
        update_particles(particles, global_best);
        global_best = find_global_best(particles);
    }
}

main();