import * as random from 'random';

function initialize_particles(num_particles: number, dimensions: number): any[] {
    const particles: any[] = [];
    for (let _ = 0; _ < num_particles; _++) {
        const position = Array(dimensions).fill(0).map(() => random.uniform(-10, 10));
        const velocity = Array(dimensions).fill(0).map(() => random.uniform(-1, 1));
        particles.push({ position, velocity, best_position: position });
    }
    return particles;
}

function evaluate_fitness(particles: any[], fitness_function: (position: number[]) => number): void {
    for (const particle of particles) {
        particle.fitness = fitness_function(particle.position);
    }
}

function update_particles(particles: any[], global_best_position: number[], inertia_weight: number, cognitive_weight: number, social_weight: number): void {
    for (const particle of particles) {
        for (let i = 0; i < particle.position.length; i++) {
            const r1 = random.random();
            const r2 = random.random();
            const cognitive_velocity = cognitive_weight * r1 * (particle.best_position[i] - particle.position[i]);
            const social_velocity = social_weight * r2 * (global_best_position[i] - particle.position[i]);
            particle.velocity[i] = inertia_weight * particle.velocity[i] + cognitive_velocity + social_velocity;
            particle.position[i] += particle.velocity[i];
        }
        if (fitness_function(particle.position) < fitness_function(particle.best_position)) {
            particle.best_position = particle.position;
        }
    }
}

function find_global_best(particles: any[]): number[] {
    const best_particle = particles.reduce((prev, curr) => prev.fitness < curr.fitness ? prev : curr);
    return best_particle.position;
}

function fitness_function(position: number[]): number {
    return position.reduce((sum, x) => sum + x ** 2, 0);
}

function main(): void {
    const num_particles = 30;
    const dimensions = 2;
    const inertia_weight = 0.7;
    const cognitive_weight = 1.5;
    const social_weight = 1.5;
    const particles = initialize_particles(num_particles, dimensions);
    while (true) {
        evaluate_fitness(particles, fitness_function);
        const global_best_position = find_global_best(particles);
        update_particles(particles, global_best_position, inertia_weight, cognitive_weight, social_weight);
    }
}

main();