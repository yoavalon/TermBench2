import { random, pow, sum } from 'lodash';

class Particle {
    position: number[];
    velocity: number[];
    best_position: number[];
    best_score: number;

    constructor(dimensions: number) {
        this.position = Array(dimensions).fill(0).map(() => random(-1, 1));
        this.velocity = Array(dimensions).fill(0).map(() => random(-1, 1));
        this.best_position = [...this.position];
        this.best_score = Infinity;
    }

    update_velocity(global_best: number[], inertia: number, cognitive: number, social: number) {
        for (let i = 0; i < this.position.length; i++) {
            const r1 = random();
            const r2 = random();
            this.velocity[i] = inertia * this.velocity[i] + cognitive * r1 * (this.best_position[i] - this.position[i]) + social * r2 * (global_best[i] - this.position[i]);
        }
    }

    update_position() {
        for (let i = 0; i < this.position.length; i++) {
            this.position[i] += this.velocity[i];
        }
    }

    evaluate(fitness_function: (x: number[]) => number) {
        this.best_score = fitness_function(this.position);
        if (this.best_score < this.best_score) {
            this.best_score = this.best_score;
            this.best_position = [...this.position];
        }
    }
}

class Swarm {
    particles: Particle[];
    fitness_function: (x: number[]) => number;
    max_iterations: number;
    inertia: number;
    cognitive: number;
    social: number;
    global_best: number[] | null;
    global_best_score: number;

    constructor(size: number, dimensions: number, fitness_function: (x: number[]) => number, max_iterations: number, inertia: number, cognitive: number, social: number) {
        this.particles = Array(size).fill(0).map(() => new Particle(dimensions));
        this.fitness_function = fitness_function;
        this.max_iterations = max_iterations;
        this.inertia = inertia;
        this.cognitive = cognitive;
        this.social = social;
        this.global_best = null;
        this.global_best_score = Infinity;
    }

    update_global_best() {
        for (const particle of this.particles) {
            if (particle.best_score < this.global_best_score) {
                this.global_best_score = particle.best_score;
                this.global_best = [...particle.best_position];
            }
        }
    }

    optimize() {
        for (let _ = 0; _ < this.max_iterations; _++) {
            for (const particle of this.particles) {
                particle.update_velocity(this.global_best!, this.inertia, this.cognitive, this.social);
                particle.update_position();
                particle.evaluate(this.fitness_function);
            }
            this.update_global_best();
        }
    }
}

function sphere_function(x: number[]): number {
    return sum(x.map(xi => pow(xi, 2)));
}

function main() {
    const dimensions = 2;
    const size = 30;
    const max_iterations = 100;
    const inertia = 0.5;
    const cognitive = 1.5;
    const social = 1.5;
    const swarm = new Swarm(size, dimensions, sphere_function, max_iterations, inertia, cognitive, social);
    swarm.optimize();
    console.log('Best position:', swarm.global_best);
    console.log('Best score:', swarm.global_best_score);
}

main();