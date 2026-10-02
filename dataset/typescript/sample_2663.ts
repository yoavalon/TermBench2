import * as math from 'mathjs';
import * as random from 'random';

class Swarm {
    size: number;
    dimensions: number;
    particles: Particle[];
    global_best: Particle | null;

    constructor(size: number, dimensions: number) {
        this.size = size;
        this.dimensions = dimensions;
        this.particles = Array.from({ length: size }, () => new Particle(dimensions));
        this.global_best = null;
    }

    update_global_best() {
        for (const particle of this.particles) {
            if (this.global_best === null || particle.best_score < this.global_best.best_score) {
                this.global_best = particle;
            }
        }
    }

    update_particles() {
        for (const particle of this.particles) {
            particle.update_velocity(this.global_best);
            particle.update_position();
        }
    }
}

class Particle {
    position: number[];
    velocity: number[];
    best_position: number[];
    best_score: number;

    constructor(dimensions: number) {
        this.position = Array.from({ length: dimensions }, () => random.uniform(-10, 10));
        this.velocity = Array.from({ length: dimensions }, () => random.uniform(-1, 1));
        this.best_position = [...this.position];
        this.best_score = Infinity;
    }

    update_velocity(global_best: Particle | null) {
        const w = 0.729;
        const c1 = 1.494;
        const c2 = 1.494;
        for (let i = 0; i < this.velocity.length; i++) {
            const r1 = random.random();
            const r2 = random.random();
            const cognitive = c1 * r1 * (this.best_position[i] - this.position[i]);
            const social = c2 * r2 * (global_best ? global_best.best_position[i] : 0 - this.position[i]);
            this.velocity[i] = w * this.velocity[i] + cognitive + social;
        }
    }

    update_position() {
        for (let i = 0; i < this.position.length; i++) {
            this.position[i] += this.velocity[i];
            this.position[i] = Math.max(-10, Math.min(10, this.position[i]));
        }
    }

    evaluate(objective_function: (x: number[]) => number) {
        this.best_score = objective_function(this.position);
        if (this.best_score < this.best_score) {
            this.best_position = [...this.position];
        }
    }
}

function objective_function(x: number[]): number {
    return x.reduce((sum, xi) => sum + Math.pow(xi, 2), 0);
}

function main() {
    const swarm_size = 30;
    const dimensions = 2;
    const swarm = new Swarm(swarm_size, dimensions);
    for (let i = 0; i < 100; i++) {
        swarm.update_global_best();
        for (const particle of swarm.particles) {
            particle.evaluate(objective_function);
        }
        swarm.update_particles();
    }
    console.log(swarm.global_best ? swarm.global_best.best_score : null, swarm.global_best ? swarm.global_best.best_position : null);
}

main();