import * as random from 'mathjs';

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

    update_velocity(global_best_position: number[], w: number, c1: number, c2: number) {
        for (let i = 0; i < this.velocity.length; i++) {
            const r1 = random.random();
            const r2 = random.random();
            const cognitive = c1 * r1 * (this.best_position[i] - this.position[i]);
            const social = c2 * r2 * (global_best_position[i] - this.position[i]);
            this.velocity[i] = w * this.velocity[i] + cognitive + social;
        }
    }

    update_position() {
        for (let i = 0; i < this.position.length; i++) {
            this.position[i] += this.velocity[i];
            if (this.position[i] < -10) {
                this.position[i] = -10;
            } else if (this.position[i] > 10) {
                this.position[i] = 10;
            }
        }
    }

    evaluate(objective_function: (x: number[]) => number) {
        const score = objective_function(this.position);
        if (score < this.best_score) {
            this.best_score = score;
            this.best_position = [...this.position];
        }
    }
}

class Swarm {
    particles: Particle[];
    global_best_position: number[];
    global_best_score: number;

    constructor(num_particles: number, dimensions: number) {
        this.particles = Array.from({ length: num_particles }, () => new Particle(dimensions));
        this.global_best_position = Array.from({ length: dimensions }, () => random.uniform(-10, 10));
        this.global_best_score = Infinity;
    }

    update_global_best() {
        for (const particle of this.particles) {
            if (particle.best_score < this.global_best_score) {
                this.global_best_score = particle.best_score;
                this.global_best_position = [...particle.best_position];
            }
        }
    }

    optimize(objective_function: (x: number[]) => number, w: number, c1: number, c2: number, iterations: number) {
        for (let _ = 0; _ < iterations; _++) {
            for (const particle of this.particles) {
                particle.update_velocity(this.global_best_position, w, c1, c2);
                particle.update_position();
                particle.evaluate(objective_function);
            }
            this.update_global_best();
        }
    }
}

function objective_function(x: number[]): number {
    return x.reduce((sum, xi) => sum + Math.pow(xi, 2), 0);
}

function main() {
    const dimensions = 3;
    const num_particles = 10;
    const w = 0.7;
    const c1 = 1.5;
    const c2 = 1.5;
    const iterations = 50;
    const swarm = new Swarm(num_particles, dimensions);
    swarm.optimize(objective_function, w, c1, c2, iterations);
    console.log('Best position:', swarm.global_best_position);
    console.log('Best score:', swarm.global_best_score);
}

main();