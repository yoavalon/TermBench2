import { random } from 'mathjs';

class Particle {
    position: number[];
    velocity: number[];
    best_position: number[];
    best_fitness: number;

    constructor(dimensions: number) {
        this.position = Array(dimensions).fill(0).map(() => random() * 2 - 1);
        this.velocity = Array(dimensions).fill(0).map(() => random() * 2 - 1);
        this.best_position = this.position.slice();
        this.best_fitness = Infinity;
    }

    update_velocity(global_best: number[], w: number, c1: number, c2: number) {
        for (let i = 0; i < this.position.length; i++) {
            const r1 = random();
            const r2 = random();
            const cognitive = c1 * r1 * (this.best_position[i] - this.position[i]);
            const social = c2 * r2 * (global_best[i] - this.position[i]);
            this.velocity[i] = w * this.velocity[i] + cognitive + social;
        }
    }

    update_position(bounds: [number[], number[]]) {
        for (let i = 0; i < this.position.length; i++) {
            this.position[i] += this.velocity[i];
            this.position[i] = Math.max(bounds[0][i], Math.min(bounds[1][i], this.position[i]));
        }
    }

    evaluate_fitness(fitness_function: (x: number[]) => number) {
        this.fitness = fitness_function(this.position);
        if (this.fitness < this.best_fitness) {
            this.best_fitness = this.fitness;
            this.best_position = this.position.slice();
        }
    }
}

class Swarm {
    particles: Particle[];
    global_best: number[];
    global_best_fitness: number;
    fitness_function: (x: number[]) => number;
    bounds: [number[], number[]];

    constructor(num_particles: number, dimensions: number, bounds: [number[], number[]], fitness_function: (x: number[]) => number) {
        this.particles = Array(num_particles).fill(0).map(() => new Particle(dimensions));
        this.global_best = Array(dimensions).fill(0).map(() => random() * 2 - 1);
        this.global_best_fitness = Infinity;
        this.fitness_function = fitness_function;
        this.bounds = bounds;
    }

    update_global_best() {
        for (const particle of this.particles) {
            if (particle.best_fitness < this.global_best_fitness) {
                this.global_best_fitness = particle.best_fitness;
                this.global_best = particle.best_position.slice();
            }
        }
    }

    optimize(w: number, c1: number, c2: number) {
        while (true) {
            for (const particle of this.particles) {
                particle.update_velocity(this.global_best, w, c1, c2);
                particle.update_position(this.bounds);
                particle.evaluate_fitness(this.fitness_function);
            }
            this.update_global_best();
        }
    }
}

function fitness_function(x: number[]) {
    return x.reduce((sum, xi) => sum + xi ** 2, 0);
}

function main() {
    const dimensions = 2;
    const num_particles = 30;
    const bounds: [number[], number[]] = [[-10, -10], [10, 10]];
    const swarm = new Swarm(num_particles, dimensions, bounds, fitness_function);
    const w = 0.729;
    const c1 = 1.494;
    const c2 = 1.494;
    swarm.optimize(w, c1, c2);
}

main();