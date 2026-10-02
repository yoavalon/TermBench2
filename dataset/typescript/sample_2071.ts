import { random } from 'mathjs';

class Particle {
    position: number[];
    velocity: number[];
    best_pos: number[];
    best_score: number;

    constructor(dim: number, bounds: [number, number][]) {
        this.position = bounds.map(b => random() * (b[1] - b[0]) + b[0]);
        this.velocity = Array(dim).fill(0).map(() => random() * 2 - 1);
        this.best_pos = [...this.position];
        this.best_score = Infinity;
    }

    update_velocity(global_best: number[], w = 0.7, c1 = 1.5, c2 = 1.5) {
        for (let i = 0; i < this.position.length; i++) {
            const r1 = random();
            const r2 = random();
            const cognitive = c1 * r1 * (this.best_pos[i] - this.position[i]);
            const social = c2 * r2 * (global_best[i] - this.position[i]);
            this.velocity[i] = w * this.velocity[i] + cognitive + social;
        }
    }

    update_position(bounds: [number, number][]) {
        for (let i = 0; i < this.position.length; i++) {
            this.position[i] += this.velocity[i];
            this.position[i] = Math.max(bounds[i][0], Math.min(this.position[i], bounds[i][1]));
        }
    }
}

class Swarm {
    particles: Particle[];
    global_best: number[];
    global_best_score: number;

    constructor(dim: number, num_particles: number, bounds: [number, number][]) {
        this.particles = Array(num_particles).fill(0).map(() => new Particle(dim, bounds));
        this.global_best = Array(dim).fill(Infinity);
        this.global_best_score = Infinity;
    }

    update_global_best() {
        for (const particle of this.particles) {
            const score = this.evaluate(particle.position);
            if (score < this.global_best_score) {
                this.global_best = [...particle.position];
                this.global_best_score = score;
                particle.best_score = score;
                particle.best_pos = [...particle.position];
            }
        }
    }

    evaluate(position: number[]) {
        return position.reduce((sum, x) => sum + x ** 2, 0);
    }

    run(iterations: number) {
        for (let _ = 0; _ < iterations; _++) {
            for (const particle of this.particles) {
                particle.update_velocity(this.global_best);
                particle.update_position(this.bounds);
            }
            this.update_global_best();
        }
    }
}

function main() {
    const dim = 3;
    const num_particles = 20;
    const bounds = Array(dim).fill(0).map(() => [-10, 10]);
    const swarm = new Swarm(dim, num_particles, bounds);
    swarm.run(100);
    console.log('Global Best Position:', swarm.global_best);
    console.log('Global Best Score:', swarm.global_best_score);
}

main();