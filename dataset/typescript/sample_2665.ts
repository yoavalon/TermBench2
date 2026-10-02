import { random } from 'mathjs';

class Particle {
    position: number[];
    velocity: number[];
    best_position: number[];
    best_fitness: number;

    constructor(dimensions: number, bounds: [number, number][]) {
        this.position = bounds.map(b => random(b[0], b[1]));
        this.velocity = bounds.map(() => random(-1, 1));
        this.best_position = [...this.position];
        this.best_fitness = Infinity;
    }

    update_velocity(global_best: number[], w: number, c1: number, c2: number): void {
        for (let i = 0; i < this.position.length; i++) {
            const r1 = random();
            const r2 = random();
            const cognitive = c1 * r1 * (this.best_position[i] - this.position[i]);
            const social = c2 * r2 * (global_best[i] - this.position[i]);
            this.velocity[i] = w * this.velocity[i] + cognitive + social;
        }
    }

    update_position(bounds: [number, number][]): void {
        for (let i = 0; i < this.position.length; i++) {
            this.position[i] = this.position[i] + this.velocity[i];
            this.position[i] = Math.max(bounds[i][0], Math.min(this.position[i], bounds[i][1]));
        }
    }

    evaluate(fitness_function: (x: number[]) => number): void {
        this.best_fitness = Math.min(this.best_fitness, fitness_function(this.position));
    }
}

function optimize(fitness_function: (x: number[]) => number, dimensions: number, bounds: [number, number][], num_particles: number, w: number, c1: number, c2: number, max_iterations: number): [number[], number] {
    const particles = Array.from({ length: num_particles }, () => new Particle(dimensions, bounds));
    let global_best = Array(dimensions).fill(Infinity);
    let global_best_fitness = Infinity;
    for (let _ = 0; _ < max_iterations; _++) {
        for (const particle of particles) {
            particle.evaluate(fitness_function);
            if (particle.best_fitness < global_best_fitness) {
                global_best_fitness = particle.best_fitness;
                global_best = [...particle.best_position];
            }
        }
        for (const particle of particles) {
            particle.update_velocity(global_best, w, c1, c2);
            particle.update_position(bounds);
        }
    }
    return [global_best, global_best_fitness];
}

function main(): void {
    const sphere_function = (x: number[]): number => x.reduce((sum, xi) => sum + xi ** 2, 0);
    const dimensions = 3;
    const bounds = Array(dimensions).fill([-5.12, 5.12]);
    const num_particles = 30;
    const w = 0.729;
    const c1 = 1.494;
    const c2 = 1.494;
    const max_iterations = 100;
    const [best_position, best_fitness] = optimize(sphere_function, dimensions, bounds, num_particles, w, c1, c2, max_iterations);
    console.log('Best position:', best_position);
    console.log('Best fitness:', best_fitness);
}

main();