class Particle {
    position: number[];
    velocity: number[];
    best_position: number[];
    best_score: number;

    constructor(dimensions: number, bounds: [number, number][]) {
        this.position = bounds.map(b => Math.random() * (b[1] - b[0]) + b[0]);
        this.velocity = Array(dimensions).fill(0).map(() => Math.random() * 2 - 1);
        this.best_position = [...this.position];
        this.best_score = Infinity;
    }

    update_velocity(global_best: number[], w: number, c1: number, c2: number): void {
        for (let i = 0; i < this.velocity.length; i++) {
            const r1 = Math.random();
            const r2 = Math.random();
            const cognitive = c1 * r1 * (this.best_position[i] - this.position[i]);
            const social = c2 * r2 * (global_best[i] - this.position[i]);
            this.velocity[i] = w * this.velocity[i] + cognitive + social;
        }
    }

    update_position(bounds: [number, number][]): void {
        for (let i = 0; i < this.position.length; i++) {
            this.position[i] += this.velocity[i];
            this.position[i] = Math.max(bounds[i][0], Math.min(bounds[i][1], this.position[i]));
        }
    }
}

class Swarm {
    particles: Particle[];
    best_position: number[] | null;
    best_score: number;
    function: (x: number[]) => number;

    constructor(num_particles: number, dimensions: number, bounds: [number, number][], function: (x: number[]) => number) {
        this.particles = Array(num_particles).fill(0).map(() => new Particle(dimensions, bounds));
        this.best_position = null;
        this.best_score = Infinity;
        this.function = function;
    }

    optimize(max_iterations: number, w: number, c1: number, c2: number): void {
        for (let _ = 0; _ < max_iterations; _++) {
            for (const particle of this.particles) {
                const score = this.function(particle.position);
                if (score < particle.best_score) {
                    particle.best_score = score;
                    particle.best_position = [...particle.position];
                }
                if (score < this.best_score) {
                    this.best_score = score;
                    this.best_position = [...particle.position];
                }
            }
            for (const particle of this.particles) {
                particle.update_velocity(this.best_position!, w, c1, c2);
                particle.update_position(bounds);
            }
        }
    }
}

function objective_function(x: number[]): number {
    return x.reduce((acc, xi) => acc + Math.pow(xi - 2, 2), 0);
}

function main(): void {
    const dimensions = 3;
    const bounds = Array(dimensions).fill(0).map(() => [-10, 10]);
    const num_particles = 20;
    const max_iterations = 100;
    const w = 0.7;
    const c1 = 1.5;
    const c2 = 1.5;
    const swarm = new Swarm(num_particles, dimensions, bounds, objective_function);
    swarm.optimize(max_iterations, w, c1, c2);
    console.log(swarm.best_position, swarm.best_score);
}

main();