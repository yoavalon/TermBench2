import * as random from 'random';

class Particle {
    position: number[];
    velocity: number[];
    best_position: number[];
    best_score: number;

    constructor(dimensions: number, position?: number[]) {
        this.position = position !== undefined ? position : Array.from({ length: dimensions }, () => random.uniform(-1, 1));
        this.velocity = Array.from({ length: dimensions }, () => random.uniform(-1, 1));
        this.best_position = [...this.position];
        this.best_score = Infinity;
    }

    update_velocity(global_best: number[], w = 0.7, c1 = 1.5, c2 = 1.5) {
        for (let i = 0; i < this.position.length; i++) {
            const r1 = random.random();
            const r2 = random.random();
            const cognitive = c1 * r1 * (this.best_position[i] - this.position[i]);
            const social = c2 * r2 * (global_best[i] - this.position[i]);
            this.velocity[i] = w * this.velocity[i] + cognitive + social;
        }
    }

    update_position(bounds?: [number, number]) {
        for (let i = 0; i < this.position.length; i++) {
            this.position[i] += this.velocity[i];
            if (bounds) {
                this.position[i] = Math.max(bounds[0], Math.min(bounds[1], this.position[i]));
            }
        }
    }

    evaluate(functionToEvaluate: (x: number[]) => number) {
        this.current_score = functionToEvaluate(this.position);
        if (this.current_score < this.best_score) {
            this.best_score = this.current_score;
            this.best_position = [...this.position];
        }
    }
}

class Swarm {
    particles: Particle[];
    global_best: number[] | null;
    global_best_score: number;
    bounds: [number, number] | null;

    constructor(dimensions: number, num_particles: number, bounds?: [number, number]) {
        this.particles = Array.from({ length: num_particles }, () => new Particle(dimensions));
        this.global_best = null;
        this.global_best_score = Infinity;
        this.bounds = bounds;
    }

    update_global_best() {
        for (const particle of this.particles) {
            if (particle.best_score < this.global_best_score) {
                this.global_best_score = particle.best_score;
                this.global_best = [...particle.best_position];
            }
        }
    }

    optimize(functionToOptimize: (x: number[]) => number, iterations: number) {
        for (let i = 0; i < iterations; i++) {
            this.update_global_best();
            for (const particle of this.particles) {
                particle.update_velocity(this.global_best!);
                particle.update_position(this.bounds);
                particle.evaluate(functionToOptimize);
            }
        }
    }
}

function objective_function(x: number[]) {
    return x.reduce((sum, xi) => sum + xi ** 2, 0);
}

function main() {
    const dimensions = 2;
    const num_particles = 30;
    const bounds: [number, number] = [-10, 10];
    const iterations = 100;
    const swarm = new Swarm(dimensions, num_particles, bounds);
    swarm.optimize(objective_function, iterations);
    console.log('Global Best Position:', swarm.global_best);
    console.log('Global Best Score:', swarm.global_best_score);
}

main();