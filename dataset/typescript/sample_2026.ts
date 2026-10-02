import * as random from 'random-js';

function initialize_particles(size: number, dimensions: number): any[] {
    const particles = [];
    for (let _ = 0; _ < size; _++) {
        const engine = random.engines.mt19937().autoSeed();
        const position = Array(dimensions).fill(0).map(() => random.uniform(engine, -10, 10));
        const velocity = Array(dimensions).fill(0).map(() => random.uniform(engine, -1, 1));
        const pbest_position = [...position];
        const pbest_value = Infinity;
        particles.push({ position, velocity, pbest_position, pbest_value });
    }
    return particles;
}

function update_velocity(particles: any[], gbest_position: number[], w = 0.7, c1 = 1.5, c2 = 1.5): void {
    for (const particle of particles) {
        for (let i = 0; i < particle.position.length; i++) {
            const r1 = random.real(engine, 0, 1);
            const r2 = random.real(engine, 0, 1);
            const cognitive = c1 * r1 * (particle.pbest_position[i] - particle.position[i]);
            const social = c2 * r2 * (gbest_position[i] - particle.position[i]);
            particle.velocity[i] = w * particle.velocity[i] + cognitive + social;
        }
    }
}

function update_position(particles: any[], bounds: [number, number]): void {
    for (const particle of particles) {
        for (let i = 0; i < particle.position.length; i++) {
            particle.position[i] += particle.velocity[i];
            particle.position[i] = Math.max(bounds[0], Math.min(particle.position[i], bounds[1]));
        }
    }
}

function evaluate(particles: any[], objective_function: (x: number[]) => number): void {
    for (const particle of particles) {
        const value = objective_function(particle.position);
        if (value < particle.pbest_value) {
            particle.pbest_value = value;
            particle.pbest_position = [...particle.position];
        }
    }
}

function find_gbest(particles: any[]): number[] {
    let gbest_value = Infinity;
    let gbest_position = null;
    for (const particle of particles) {
        if (particle.pbest_value < gbest_value) {
            gbest_value = particle.pbest_value;
            gbest_position = [...particle.pbest_position];
        }
    }
    return gbest_position;
}

function optimize(objective_function: (x: number[]) => number, dimensions: number, size: number, iterations: number, bounds: [number, number]): number[] {
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

function main(): void {
    const sphere_function = (x: number[]) => x.reduce((sum, xi) => sum + Math.pow(xi, 2), 0);
    const dimensions = 30;
    const size = 30;
    const iterations = 100;
    const bounds = [-10, 10];
    const result = optimize(sphere_function, dimensions, size, iterations, bounds);
    console.log(result);
}

main();