import * as random from 'random';

class Particle {
    position: number[];
    velocity: number[];
    best_position: number[];
    best_fitness: number;

    constructor(dim: number, lb: number, ub: number) {
        this.position = Array.from({ length: dim }, () => random.uniform(lb, ub));
        this.velocity = Array.from({ length: dim }, () => random.uniform(-1, 1));
        this.best_position = [...this.position];
        this.best_fitness = Infinity;
    }

    update_velocity(global_best: number[], w: number, c1: number, c2: number) {
        for (let i = 0; i < this.velocity.length; i++) {
            const r1 = random.random();
            const r2 = random.random();
            const cognitive = c1 * r1 * (this.best_position[i] - this.position[i]);
            const social = c2 * r2 * (global_best[i] - this.position[i]);
            this.velocity[i] = w * this.velocity[i] + cognitive + social;
        }
    }

    update_position(lb: number, ub: number) {
        for (let i = 0; i < this.position.length; i++) {
            this.position[i] += this.velocity[i];
            if (this.position[i] < lb) {
                this.position[i] = lb;
            }
            if (this.position[i] > ub) {
                this.position[i] = ub;
            }
        }
    }
}

function fitness_function(x: number[]): number {
    return x.reduce((acc, xi) => acc + xi ** 2, 0);
}

function optimize(dim: number, lb: number, ub: number, num_particles: number, w: number, c1: number, c2: number, max_iter: number): [number[], number] {
    const particles = Array.from({ length: num_particles }, () => new Particle(dim, lb, ub));
    let global_best = Array.from({ length: dim }, () => Infinity);
    let global_best_fitness = Infinity;

    for (let _ = 0; _ < max_iter; _++) {
        for (const particle of particles) {
            const current_fitness = fitness_function(particle.position);
            if (current_fitness < particle.best_fitness) {
                particle.best_fitness = current_fitness;
                particle.best_position = [...particle.position];
            }
            if (current_fitness < global_best_fitness) {
                global_best_fitness = current_fitness;
                global_best = [...particle.position];
            }
        }
        for (const particle of particles) {
            particle.update_velocity(global_best, w, c1, c2);
            particle.update_position(lb, ub);
        }
    }
    return [global_best, global_best_fitness];
}

function main() {
    const dim = 30;
    const lb = -100;
    const ub = 100;
    const num_particles = 50;
    const w = 0.7;
    const c1 = 1.5;
    const c2 = 1.5;
    const max_iter = 10000;
    const [best_position, best_fitness] = optimize(dim, lb, ub, num_particles, w, c1, c2, max_iter);
    console.log('Best position:', best_position);
    console.log('Best fitness:', best_fitness);
}

main();