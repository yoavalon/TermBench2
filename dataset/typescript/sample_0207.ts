import { random } from 'mathjs';

function initialize_particles(num_particles: number, num_dimensions: number): { position: number[], velocity: number[], best_position: number[] }[] {
    const particles: { position: number[], velocity: number[], best_position: number[] }[] = [];
    for (let _ = 0; _ < num_particles; _++) {
        const position = Array.from({ length: num_dimensions }, () => random(-10, 10));
        const velocity = Array.from({ length: num_dimensions }, () => random(-1, 1));
        particles.push({ position, velocity, best_position: [...position] });
    }
    return particles;
}

function update_velocity(particles: { position: number[], velocity: number[], best_position: number[] }[], global_best: { position: number[], velocity: number[], best_position: number[] }, w: number, c1: number, c2: number): void {
    for (const particle of particles) {
        const r1 = random();
        const r2 = random();
        for (let i = 0; i < particle.position.length; i++) {
            const cognitive_velocity = c1 * r1 * (particle.best_position[i] - particle.position[i]);
            const social_velocity = c2 * r2 * (global_best.position[i] - particle.position[i]);
            particle.velocity[i] = w * particle.velocity[i] + cognitive_velocity + social_velocity;
        }
    }
}

function update_position(particles: { position: number[], velocity: number[], best_position: number[] }[]): void {
    for (const particle of particles) {
        for (let i = 0; i < particle.position.length; i++) {
            particle.position[i] += particle.velocity[i];
        }
    }
}

function evaluate_fitness(particles: { position: number[], velocity: number[], best_position: number[] }[], fitness_function: (position: number[]) => number): { position: number[], velocity: number[], best_position: number[] } {
    for (const particle of particles) {
        const fitness = fitness_function(particle.position);
        if (fitness < fitness_function(particle.best_position)) {
            particle.best_position = [...particle.position];
        }
    }
    return particles.reduce((a, b) => fitness_function(a.best_position) < fitness_function(b.best_position) ? a : b);
}

function main(): void {
    const num_particles = 20;
    const num_dimensions = 2;
    const w = 0.7;
    const c1 = 1.5;
    const c2 = 1.5;
    const max_iterations = 100;

    const fitness_function = (position: number[]): number => position.reduce((acc, x) => acc + x ** 2, 0);
    const particles = initialize_particles(num_particles, num_dimensions);
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