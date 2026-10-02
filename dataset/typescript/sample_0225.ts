import * as random from 'mathjs';

class PSOSettings {
    dimensions: number;
    population_size: number;
    max_iterations: number;
    c1: number;
    c2: number;
    w: number;

    constructor(dimensions: number, population_size: number, max_iterations: number) {
        this.dimensions = dimensions;
        this.population_size = population_size;
        this.max_iterations = max_iterations;
        this.c1 = 2.0;
        this.c2 = 2.0;
        this.w = 0.7;
    }
}

class Particle {
    position: number[];
    velocity: number[];
    best_position: number[];
    best_fitness: number;

    constructor(dimensions: number, lower_bound: number, upper_bound: number) {
        this.position = Array.from({ length: dimensions }, () => random.uniform(lower_bound, upper_bound));
        this.velocity = Array.from({ length: dimensions }, () => random.uniform(-1, 1));
        this.best_position = [...this.position];
        this.best_fitness = Infinity;
    }
}

function fitness(position: number[]): number {
    return position.reduce((sum, x) => sum + x ** 2, 0);
}

function update_velocity(particle: Particle, global_best: number[], settings: PSOSettings): void {
    for (let i = 0; i < settings.dimensions; i++) {
        const r1 = random.random();
        const r2 = random.random();
        const cognitive = settings.c1 * r1 * (particle.best_position[i] - particle.position[i]);
        const social = settings.c2 * r2 * (global_best[i] - particle.position[i]);
        particle.velocity[i] = settings.w * particle.velocity[i] + cognitive + social;
    }
}

function update_position(particle: Particle, settings: PSOSettings): void {
    for (let i = 0; i < settings.dimensions; i++) {
        particle.position[i] += particle.velocity[i];
        if (particle.position[i] < -10) {
            particle.position[i] = -10;
        } else if (particle.position[i] > 10) {
            particle.position[i] = 10;
        }
    }
}

function optimize(settings: PSOSettings): [number[], number] {
    const population = Array.from({ length: settings.population_size }, () => new Particle(settings.dimensions, -10, 10));
    const global_best = Array(settings.dimensions).fill(0);
    let global_best_fitness = Infinity;

    for (let iteration = 0; iteration < settings.max_iterations; iteration++) {
        for (const particle of population) {
            const current_fitness = fitness(particle.position);
            if (current_fitness < particle.best_fitness) {
                particle.best_fitness = current_fitness;
                particle.best_position = [...particle.position];
            }
            if (current_fitness < global_best_fitness) {
                global_best_fitness = current_fitness;
                global_best.splice(0, global_best.length, ...particle.position);
            }
        }
        for (const particle of population) {
            update_velocity(particle, global_best, settings);
            update_position(particle, settings);
        }
    }
    return [global_best, global_best_fitness];
}

function main(): void {
    const settings = new PSOSettings(2, 30, 100);
    const [best_position, best_fitness] = optimize(settings);
    console.log('Best position:', best_position);
    console.log('Best fitness:', best_fitness);
}

main();