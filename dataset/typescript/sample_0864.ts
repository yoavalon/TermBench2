import * as random from 'mathjs';

class Particle {
    position: number[];
    velocity: number[];
    best_position: number[];
    best_score: number;

    constructor(dimensions: number) {
        this.position = Array(dimensions).fill(0).map(() => random.uniform(-10, 10));
        this.velocity = Array(dimensions).fill(0).map(() => random.uniform(-1, 1));
        this.best_position = [...this.position];
        this.best_score = Infinity;
    }

    update_velocity(global_best_position: number[], w: number, c1: number, c2: number): void {
        for (let i = 0; i < this.position.length; i++) {
            const r1 = random.random();
            const r2 = random.random();
            const cognitive = c1 * r1 * (this.best_position[i] - this.position[i]);
            const social = c2 * r2 * (global_best_position[i] - this.position[i]);
            this.velocity[i] = w * this.velocity[i] + cognitive + social;
        }
    }

    update_position(): void {
        for (let i = 0; i < this.position.length; i++) {
            this.position[i] += this.velocity[i];
        }
    }

    evaluate(fitness_function: (x: number[]) => number): number {
        this.best_score = fitness_function(this.position);
        return this.best_score;
    }
}

class Swarm {
    particles: Particle[];
    global_best_position: number[];
    global_best_score: number;

    constructor(num_particles: number, dimensions: number) {
        this.particles = Array(num_particles).fill(0).map(() => new Particle(dimensions));
        this.global_best_position = Array(dimensions).fill(0).map(() => random.uniform(-10, 10));
        this.global_best_score = Infinity;
    }

    update_global_best(): void {
        for (const particle of this.particles) {
            if (particle.best_score < this.global_best_score) {
                this.global_best_score = particle.best_score;
                this.global_best_position = [...particle.best_position];
            }
        }
    }
}

function fitness_function(x: number[]): number {
    return x.reduce((sum, xi) => sum + Math.pow(xi, 2), 0);
}

function optimize(swarm: Swarm, w: number, c1: number, c2: number, iterations: number): [number[], number] {
    for (let i = 0; i < iterations; i++) {
        for (const particle of swarm.particles) {
            particle.update_velocity(swarm.global_best_position, w, c1, c2);
            particle.update_position();
            particle.evaluate(fitness_function);
        }
        swarm.update_global_best();
    }
    return [swarm.global_best_position, swarm.global_best_score];
}

function main(): void {
    const dimensions = 10;
    const num_particles = 20;
    const w = 0.7;
    const c1 = 2.0;
    const c2 = 2.0;
    const iterations = 100;
    const swarm = new Swarm(num_particles, dimensions);
    const [best_position, best_score] = optimize(swarm, w, c1, c2, iterations);
    console.log('Best position:', best_position);
    console.log('Best score:', best_score);
}

main();