import * as random from 'random';

function initialize_particles(dimensions: number, count: number): { position: number[], velocity: number[], best_position: number[] }[] {
    const particles: { position: number[], velocity: number[], best_position: number[] }[] = [];
    for (let _ = 0; _ < count; _++) {
        const position = Array.from({ length: dimensions }, () => random.uniform(-10, 10));
        const velocity = Array.from({ length: dimensions }, () => random.uniform(-1, 1));
        particles.push({ position, velocity, best_position: [...position] });
    }
    return particles;
}

function evaluate_fitness(particles: { position: number[], velocity: number[], best_position: number[], fitness?: number }[], objective_function: (position: number[]) => number) {
    for (const particle of particles) {
        particle.fitness = objective_function(particle.position);
    }
}

function update_particles(particles: { position: number[], velocity: number[], best_position: number[], fitness?: number }[], global_best: { position: number[], velocity: number[], best_position: number[], fitness?: number }, inertia_weight: number, cognitive_weight: number, social_weight: number) {
    for (const particle of particles) {
        for (let i = 0; i < particle.position.length; i++) {
            const r1 = random.random();
            const r2 = random.random();
            const cognitive_velocity = cognitive_weight * r1 * (particle.best_position[i] - particle.position[i]);
            const social_velocity = social_weight * r2 * (global_best.position[i] - particle.position[i]);
            particle.velocity[i] = inertia_weight * particle.velocity[i] + cognitive_velocity + social_velocity;
            particle.position[i] += particle.velocity[i];
        }
        particle.best_position = particle.fitness < particle.fitness ? [...particle.position] : [...particle.best_position];
    }
}

function find_global_best(particles: { position: number[], velocity: number[], best_position: number[], fitness?: number }[]): { position: number[], velocity: number[], best_position: number[], fitness?: number } {
    let global_best = particles[0];
    for (let i = 1; i < particles.length; i++) {
        if (particles[i].fitness < global_best.fitness) {
            global_best = particles[i];
        }
    }
    return global_best;
}

function objective_function(position: number[]): number {
    return position.reduce((sum, x) => sum + x ** 2, 0);
}

function main() {
    const dimensions = 2;
    const particle_count = 30;
    const inertia_weight = 0.7;
    const cognitive_weight = 1.5;
    const social_weight = 1.5;
    const particles = initialize_particles(dimensions, particle_count);
    while (true) {
        evaluate_fitness(particles, objective_function);
        const global_best = find_global_best(particles);
        update_particles(particles, global_best, inertia_weight, cognitive_weight, social_weight);
    }
}

main();