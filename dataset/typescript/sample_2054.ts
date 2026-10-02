import { random } from 'mathjs';

class Particle {
    position: number[];
    velocity: number[];
    best_position: number[];
    best_value: number;

    constructor(dimensions: number) {
        this.position = Array.from({ length: dimensions }, () => random() * 2 - 1);
        this.velocity = Array.from({ length: dimensions }, () => random() * 2 - 1);
        this.best_position = [...this.position];
        this.best_value = Infinity;
    }

    update_velocity(global_best: number[], w = 0.7, c1 = 1.5, c2 = 1.5) {
        for (let i = 0; i < this.position.length; i++) {
            const r1 = random();
            const r2 = random();
            const cognitive = c1 * r1 * (this.best_position[i] - this.position[i]);
            const social = c2 * r2 * (global_best[i] - this.position[i]);
            this.velocity[i] = w * this.velocity[i] + cognitive + social;
        }
    }

    update_position() {
        for (let i = 0; i < this.position.length; i++) {
            this.position[i] += this.velocity[i];
        }
    }

    evaluate(objective_function: (x: number[]) => number) {
        this.best_value = objective_function(this.position);
        if (this.best_value < this.best_value) {
            this.best_position = [...this.position];
        }
    }
}

class Swarm {
    particles: Particle[];
    global_best: number[];
    global_best_value: number;

    constructor(dimensions: number, num_particles: number) {
        this.particles = Array.from({ length: num_particles }, () => new Particle(dimensions));
        this.global_best = Array.from({ length: dimensions }, () => Infinity);
        this.global_best_value = Infinity;
    }

    update_global_best() {
        for (const particle of this.particles) {
            if (particle.best_value < this.global_best_value) {
                this.global_best_value = particle.best_value;
                this.global_best = [...particle.best_position];
            }
        }
    }

    iterate(objective_function: (x: number[]) => number) {
        for (const particle of this.particles) {
            particle.update_velocity(this.global_best);
            particle.update_position();
            particle.evaluate(objective_function);
        }
        this.update_global_best();
    }
}

function objective_function(x: number[]): number {
    return x.reduce((sum, xi) => sum + xi ** 2, 0);
}

function optimize(dimensions: number, num_particles: number, max_iterations: number): number[] {
    const swarm = new Swarm(dimensions, num_particles);
    for (let i = 0; i < max_iterations; i++) {
        swarm.iterate(objective_function);
    }
    return swarm.global_best;
}

function main() {
    const dimensions = 10;
    const num_particles = 20;
    const max_iterations = 100;
    const best_solution = optimize(dimensions, num_particles, max_iterations);
    console.log('Best solution:', best_solution);
}

main();