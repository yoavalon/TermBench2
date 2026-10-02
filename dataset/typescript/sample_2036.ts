import * as random from 'random';

class Particle {
    position: number[];
    velocity: number[];
    best_position: number[];
    best_score: number;

    constructor(dimensions: number, lower_bound: number, upper_bound: number) {
        this.position = Array.from({ length: dimensions }, () => random.uniform(lower_bound, upper_bound));
        this.velocity = Array.from({ length: dimensions }, () => random.uniform(-1, 1));
        this.best_position = [...this.position];
        this.best_score = Infinity;
    }

    update_velocity(global_best_position: number[], w: number, c1: number, c2: number) {
        for (let i = 0; i < this.position.length; i++) {
            const r1 = random.random();
            const r2 = random.random();
            this.velocity[i] = w * this.velocity[i] + c1 * r1 * (this.best_position[i] - this.position[i]) + c2 * r2 * (global_best_position[i] - this.position[i]);
        }
    }

    update_position() {
        for (let i = 0; i < this.position.length; i++) {
            this.position[i] += this.velocity[i];
        }
    }

    evaluate(fitness_function: (position: number[]) => number) {
        this.best_score = Math.min(this.best_score, fitness_function(this.position));
        if (this.best_score < fitness_function(this.position)) {
            this.best_position = [...this.position];
        }
    }
}

class Swarm {
    particles: Particle[];
    global_best_position: number[];
    global_best_score: number;

    constructor(size: number, dimensions: number, lower_bound: number, upper_bound: number) {
        this.particles = Array.from({ length: size }, () => new Particle(dimensions, lower_bound, upper_bound));
        this.global_best_position = Array.from({ length: dimensions }, () => random.uniform(lower_bound, upper_bound));
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

    iterate(fitness_function: (position: number[]) => number, w: number, c1: number, c2: number) {
        for (const particle of this.particles) {
            particle.update_velocity(this.global_best_position, w, c1, c2);
            particle.update_position();
            particle.evaluate(fitness_function);
        }
        this.update_global_best();
    }
}

function fitness_function(position: number[]): number {
    return position.reduce((sum, x) => sum + Math.pow(x, 2), 0);
}

function main() {
    const dimensions = 2;
    const lower_bound = -10;
    const upper_bound = 10;
    const swarm_size = 30;
    const w = 0.7;
    const c1 = 1.5;
    const c2 = 1.5;
    const iterations = 100;
    const swarm = new Swarm(swarm_size, dimensions, lower_bound, upper_bound);
    for (let i = 0; i < iterations; i++) {
        swarm.iterate(fitness_function, w, c1, c2);
    }
    console.log('Global best score:', swarm.global_best_score);
    console.log('Global best position:', swarm.global_best_position);
}

main();